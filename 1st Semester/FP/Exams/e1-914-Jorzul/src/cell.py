class Cell:
    def __init__(self, row, col):
        self.row = row
        self.column = col
        self.item = " "

    def __str__(self):
        return str(self.item)
