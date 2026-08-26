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


# DataStream distributes data among the registered processors
class DataStream:
    def __init__(self) -> None:
        # stores the registered processors
        self._processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        # adds a processor to the list
        self._processors.append(proc)

    def process_stream(self, stream: list[typing.Any]) -> None:
        for item in stream:
            processed = False
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
            name = proc.__class__.__name__.replace(
                "Processor", " Processor"
            )
            print(
                f"{name}: total {proc._total_processed} items processed, "
                f"remaining {len(proc._data)} on processor"
            )


def main() -> None:
    print("=== Code Nexus - Data Stream ===")
    print("Initialize Data Stream...")
    stream = DataStream()
    stream.print_processors_stats()
    numeric = NumericProcessor()
    text = TextProcessor()
    log = LogProcessor()
    print("Registering Numeric Processor")
    stream.register_processor(numeric)
    batch: list[typing.Any] = [
        "Hello world",
        [3.14, -1, 2.71],
        [
            {"log_level": "WARNING", "log_message": "Cat used telnet"},
            {"log_level": "INFO", "log_message": "Micio is connected"}
        ],
        42,
        ["Hi", "five"]
    ]
    print("Send first batch of data on stream:", batch)
    stream.process_stream(batch)
    stream.print_processors_stats()
    print("Registering other data processors")
    stream.register_processor(text)
    stream.register_processor(log)
    print("Send the same batch again")
    stream.process_stream(batch)
    stream.print_processors_stats()
    print(
        "Consume some elements from the data processors: "
        "Numeric 3, Text 2, Log 1"
    )
    for _ in range(3):
        numeric.output()
    for _ in range(2):
        text.output()
    log.output()
    stream.print_processors_stats()


if __name__ == "__main__":
    main()

# DataStream contains a list of registered processors.
# register_processor() adds a processor to the list.
# Example: NumericProcessor, TextProcessor and LogProcessor.
# process_stream() checks one data item at a time.
# Each processor uses validate() to check if it can accept it.
# Example: 42 goes to NumericProcessor and "Micio" goes to TextProcessor.
# The first compatible processor stores the data with ingest().
# break prevents the same data from being processed more than once.
# If no processor accepts the data, an error is printed.
# print_processors_stats() shows processed data and remaining data.
# Flow: data -> DataStream -> validate() -> ingest() -> processor.
