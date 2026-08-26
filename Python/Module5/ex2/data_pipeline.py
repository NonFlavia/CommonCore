import abc
import typing


# DataProcessor inherits from ABC and can have abstract methods
# an underscore indicates an internal class attribute
class DataProcessor(abc.ABC):
    def __init__(self) -> None:
        # stores each piece of data together with its rank
        self._data: list[tuple[int, str]] = []
        # counts all processed items
        self._total_processed: int = 0

    # forces child classes to define how to validate data
    @abc.abstractmethod
    def validate(self, data: typing.Any) -> bool:
        pass

    # forces child classes to define how to process data
    @abc.abstractmethod
    def ingest(self, data: typing.Any) -> None:
        pass

    # returns and removes the oldest data item
    def output(self) -> tuple[int, str]:
        if not self._data:
            raise IndexError("No data to output")
        return self._data.pop(0)


# NumericProcessor accepts single numbers or lists of numbers
class NumericProcessor(DataProcessor):
    def validate(self, data: typing.Any) -> bool:
        # accepts int or float, but not bool
        if isinstance(data, (int, float)) and not isinstance(data, bool):
            return True
        if isinstance(data, list):
            # checks all items one by one
            for item in data:
                if not isinstance(item, (int, float)):
                    return False
                if isinstance(item, bool):
                    return False
            return True
        return False

    def ingest(self, data: int | float | list[int | float]) -> None:
        # checks the data before storing it
        if not self.validate(data):
            raise ValueError("Improper numeric data")
        values: list[int | float]
        if isinstance(data, list):
            values = data
        else:
            # puts the single number into a list
            values = [data]
        for value in values:
            # converts the number to str, stores it and increases the rank
            self._data.append((self._total_processed, str(value)))
            self._total_processed += 1


# TextProcessor accepts single strings or lists of strings
class TextProcessor(DataProcessor):
    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, str):
            return True
        if isinstance(data, list):
            # one non-str item is enough to reject the list
            for item in data:
                if not isinstance(item, str):
                    return False
            return True
        return False

    def ingest(self, data: str | list[str]) -> None:
        # checks the data before storing it
        if not self.validate(data):
            raise ValueError("Improper text data")
        values: list[str]
        if isinstance(data, list):
            values = data
        else:
            values = [data]
        for value in values:
            # value is already a string
            self._data.append((self._total_processed, value))
            self._total_processed += 1


# LogProcessor accepts dictionaries or lists of dictionaries
class LogProcessor(DataProcessor):
    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, dict):
            # checks the keys and values of a single log
            for key, value in data.items():
                if not isinstance(key, str) or not isinstance(value, str):
                    return False
            return True
        if isinstance(data, list):
            # checks each dictionary in the list
            for log in data:
                if not isinstance(log, dict):
                    return False
                for key, value in log.items():
                    if not isinstance(key, str):
                        return False
                    if not isinstance(value, str):
                        return False
            return True
        return False

    def ingest(
        self,
        data: dict[str, str] | list[dict[str, str]]
    ) -> None:
        # checks the data before storing it
        if not self.validate(data):
            raise ValueError("Improper log data")
        logs: list[dict[str, str]]
        if isinstance(data, dict):
            logs = [data]
        else:
            logs = data
        for log in logs:
            # joins the log values using ": "
            text: str = ": ".join(log.values())
            self._data.append((self._total_processed, text))
            self._total_processed += 1


# the code added in ex2 starts here
class ExportPlugin(typing.Protocol):
    # every plugin must have this method
    def process_output(
        self,
        data: list[tuple[int, str]]
    ) -> None:
        pass


# CSVPlugin follows ExportPlugin through duck typing
class CSVPlugin:
    def process_output(
        self,
        data: list[tuple[int, str]]
    ) -> None:
        values: list[str] = []
        for item in data:
            # item[1] contains the text, item[0] contains the rank
            value = item[1]
            escaped_value = value.replace('"', '""')
            special = "," in value or '"' in value
            special = special or "\n" in value or "\r" in value
            if special:
                escaped_value = f'"{escaped_value}"'
            values.append(escaped_value)
        print("CSV Output:")
        print(",".join(values))


# JSONPlugin follows ExportPlugin through duck typing
class JSONPlugin:
    def process_output(
        self,
        data: list[tuple[int, str]]
    ) -> None:
        entries: list[str] = []
        for rank, value in data:
            # escapes backslashes and quotation marks in the text
            value = value.replace("\\", "\\\\")
            value = value.replace('"', '\\"')
            value = value.replace("\b", "\\b")
            value = value.replace("\f", "\\f")
            value = value.replace("\n", "\\n")
            value = value.replace("\r", "\\r")
            value = value.replace("\t", "\\t")
            # creates an "item_rank": "value" pair
            entries.append(f'"item_{rank}": "{value}"')
        print("JSON Output:")
        print("{" + ", ".join(entries) + "}")


# DataStream distributes data among the registered processors
class DataStream:
    def __init__(self) -> None:
        # stores the registered processors
        self._processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        # adds a processor to the list
        self._processors.append(proc)

    def process_stream(self, stream: list[typing.Any]) -> None:
        # checks each received item
        for item in stream:
            processed = False
            # looks for the first compatible processor
            for proc in self._processors:
                if proc.validate(item):
                    proc.ingest(item)
                    processed = True
                    break
            if not processed:
                print(
                    "DataStream error - Can't process element in stream:",
                    item
                )

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        if not self._processors:
            print("No processor found, no data")
            return
        for proc in self._processors:
            # turns NumericProcessor into Numeric Processor
            name = proc.__class__.__name__.replace(
                "Processor", " Processor"
            )
            print(
                f"{name}: total {proc._total_processed} items processed, "
                f"remaining {len(proc._data)} on processor"
            )

    def output_pipeline(
        self,
        nb: int,
        plugin: ExportPlugin
    ) -> None:
        # takes data from each registered processor
        for proc in self._processors:
            output_data: list[tuple[int, str]] = []
            count = 0
            # stops at nb or when the processor is empty
            while count < nb and proc._data:
                output_data.append(proc.output())
                count += 1
            # sends the collected data to the selected plugin
            plugin.process_output(output_data)


def main() -> None:
    print("=== Code Nexus - Data Pipeline ===")
    print("Initialize Data Stream...")
    stream = DataStream()
    stream.print_processors_stats()
    numeric = NumericProcessor()
    text = TextProcessor()
    log = LogProcessor()
    # registers all processors
    print("Registering Processors")
    stream.register_processor(numeric)
    stream.register_processor(text)
    stream.register_processor(log)
    first_batch: list[typing.Any] = [
        "Hello world",
        [3.14, -1, 2.71],
        [
            {"log_level": "WARNING", "log_message": "Cat used telnet"},
            {"log_level": "INFO", "log_message": "Micio is connected"}
        ],
        42,
        ["Hi", "five"]
    ]
    # processes the data and shows the statistics
    print("Send first batch of data on stream:", first_batch)
    stream.process_stream(first_batch)
    stream.print_processors_stats()
    # extracts three data items from each processor in CSV format
    print("Send 3 processed data from each processor to a CSV plugin:")
    stream.output_pipeline(3, CSVPlugin())
    stream.print_processors_stats()
    # processes a second batch of data
    second_batch: list[typing.Any] = [
        21,
        ["I love AI", "LLMs are wonderful", "Stay healthy"],
        [
            {"log_level": "ERROR", "log_message": "500 server crash"},
            {"log_level": "NOTICE", "log_message": "Cat certificate expires"}
        ],
        [32, 42, 64, 84, 128, 168],
        "World hello"
    ]
    print("Send another batch of data:", second_batch)
    stream.process_stream(second_batch)
    stream.print_processors_stats()
    # extracts five data items from each processor in JSON format
    print("Send 5 processed data from each processor to a JSON plugin:")
    stream.output_pipeline(5, JSONPlugin())
    stream.print_processors_stats()


if __name__ == "__main__":
    main()

# ExportPlugin says that every plugin must have process_output().
# CSVPlugin and JSONPlugin have that method: this is duck typing.
# Example: [(0, "Micio"), (1, "Luna")]
# CSVPlugin produces: Micio,Luna
# JSONPlugin produces: {"item_0": "Micio", "item_1": "Luna"}
# output_pipeline(2, plugin) takes at most 2 cats from each processor.
# output() returns each cat and removes it from the list.
# The selected plugin finally decides how to print the cats.
# Flow: processors -> output_pipeline -> CSVPlugin/JSONPlugin.
