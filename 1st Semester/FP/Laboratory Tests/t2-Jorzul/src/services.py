from src.domain import Taxi


class TaxiService:
    def __init__(self, repository):
        self._repo = repository

    def add(self, taxi: Taxi):
        self._repo.add(taxi)

    def return_all(self):
        return self._repo.get_all()

    def ride(self, x_start, y_start, x_end, y_end):
        """

        """
        i = 0
        min_taxi = int(1000)
        while i < len(self._repo._data):
            if abs(self._repo._data[i].x - x_start) + abs(self._repo._data[i].y - y_start) < min_taxi:
                min_taxi = abs(self._repo._data[i].x - x_start) + abs(self._repo._data[i].y - y_start)
            i = i + 1

        i = 0

        while i < len(self._repo._data):
            if abs(self._repo._data[i].x - x_start) + abs(self._repo._data[i].y - y_start) == min_taxi:
                self._repo._data[i].fare = abs(x_start - x_end) + abs(y_start - y_end)
                self._repo._data[i].x = x_end
                self._repo._data[i].y = y_end
            i = i + 1
