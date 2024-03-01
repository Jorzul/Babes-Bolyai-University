import copy

from src.domain import Taxi


class MemoryRepository(object):
    def __init__(self):
        self._data = []

    def add(self, taxi: Taxi):
        self._data.append(taxi)

    def get_all(self):
        return self._data

    def change_data(self, new_list):
        self._data = copy.deepcopy(new_list)
