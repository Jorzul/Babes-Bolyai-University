import tabulate as tablt
from cell import Cell


class Board:
    def __init__(self):
        self.cells = [[Cell(row, col) for col in range(9)] for row in range(8)]

        self.header = ['0', '1', '2', '3', '4', '5', '6', '7', '8']

        ABC = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']
        for i in range(8):
            self.cells[i][0].item = ABC[i]

    def setcoord(self, row, col, entity):
        self.cells[row][col].item = entity

    def getcoord(self, row, col):
        return self.cells[row][col].item

    def coords_of_Endeavour(self):
        for i in range(0, 7):
            for j in range(1, 8):
                if self.cells[i][j].item == 'E':
                    return i, j

    def warp_Endeavour(self, E_row, E_col, x_row, y_col):
        self.cells[E_row][E_col].item = " "
        self.cells[x_row][y_col].item = 'E'

    def __str__(self):
        return tablt.tabulate(self.cells, self.header, tablefmt="grid")
