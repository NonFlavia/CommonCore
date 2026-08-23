import abc
import typing


# DataProcessor inherits from ABC, so it can have abstract methods
# one underscore marks internal class attributes
class DataProcessor(abc.ABC):
    def __init__(self) -> None:
        # stores each item together with its rank
        self._data: list[tuple[int, str]] = []
        # counts every processed item
        self._total_processed: int = 0

    # forces each subclass to define how data is validated
    @abc.abstractmethod
    def validate(self, data: typing.Any) -> bool:
        pass

    # forces each subclass to define how data is processed
    @abc.abstractmethod
    def ingest(self, data: typing.Any) -> None:
        pass

    # returns and removes the oldest item
    def output(self) -> tuple[int, str]:
        if not self._data:
            raise IndexError("No data to output")
        return self._data.pop(0)


# returns True only if the whole loop finds no mistakes
class NumericProcessor(DataProcessor):
    def validate(self, data: typing.Any) -> bool:
        # accepts one int or float, but not bool
        if isinstance(data, (int, float)) and not isinstance(data, bool):
            return True
        if isinstance(data, list):
            # checks every item, one by one
            for item in data:
                if not isinstance(item, (int, float)):
                    return False
                if isinstance(item, bool):
                    return False
            return True
        return False

    def ingest(self, data: int | float | list[int | float]) -> None:
        # validates even if ingest is called directly
        if not self.validate(data):
            raise ValueError("Improper numeric data")
        values: list[int | float]
        if isinstance(data, list):
            # if it is a list, use it directly
            values = data
        else:
            # puts one single number inside a list
            values = [data]
        for value in values:
            # converts to str, stores it and increases the rank
            self._data.append((self._total_processed, str(value)))
            self._total_processed += 1


# TextProcessor accepts one str or a list of str
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
        # protects the processor from invalid data
        if not self.validate(data):
            raise ValueError("Improper text data")
        values: list[str]
        if isinstance(data, list):
            values = data
        else:
            values = [data]
        for value in values:
            # no str(value): TextProcessor already receives strings
            self._data.append((self._total_processed, value))
            self._total_processed += 1


# LogProcessor accepts one dict or a list of dicts
class LogProcessor(DataProcessor):
    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, dict):
            # checks the keys and values of one log
            for key, value in data.items():
                if not isinstance(key, str) or not isinstance(value, str):
                    return False
            return True
        if isinstance(data, list):
            # first checks that every log is a dict
            for log in data:
                if not isinstance(log, dict):
                    return False
                # then checks the keys and values
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
        # stores nothing if the data is invalid
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
