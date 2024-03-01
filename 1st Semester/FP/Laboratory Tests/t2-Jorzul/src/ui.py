import random

from src.domain import Taxi


class UI:
    def __init__(self, serv):
        self._service = serv

    def add(self, taxi: Taxi):
        self._service.add(taxi)

    def display(self):
        for taxi in self._service.return_all():
            print(str(taxi))
        print("\n")

    def ride(self, x_start, y_start, x_end, y_end):
        self._service.ride(x_start, y_start, x_end, y_end)

    def menu(self):

        number_of_taxis = int(input("How many taxis you provide? "))

        x1 = int(random.randint(0, 100))
        y1 = int(random.randint(0, 100))

        i = 1

        while i <= number_of_taxis:

            ok = False

            x2 = int(random.randint(0, 100))
            y2 = int(random.randint(0, 100))

            if abs(x1 - x2) + abs(y1 - y2) > 4:
                ok = True

            if ok:

                id = int(i)
                self.add(Taxi(id, int(0), x1, y1))
                x1 = x2
                y1 = y2

                i = i + 1

        while True:
            print("1. Add a ride")
            print("2. Simulate a ride")
            print("3. Display")
            print("0. Exit")
            option = int(input(">"))

            if option == 1:

                xStart = int(input("x start point: "))
                yStart = int(input("y start point: "))
                xEnd = int(input("x end point: "))
                yEnd = int(input("y end point: "))

                self.ride(xStart, yStart, xEnd, yEnd)

                self.display()

            elif option == 2:
                while True:

                    ok = 0

                    xStart = int(random.randint(0, 100))
                    yStart = int(random.randint(0, 100))
                    xEnd = int(random.randint(0, 100))
                    yEnd = int(random.randint(0, 100))

                    if abs(xStart - yStart) + abs(xEnd - yEnd) > 9:
                        ok = 1

                    if ok:

                        print("Simulated coordinates:")
                        print("Start: (", xStart, ", ", yStart, ")")
                        print("End: (", xEnd, ", ", yEnd, ")")

                        self.ride(xStart, yStart, xEnd, yEnd)

                        self.display()

                        return

            elif option == 3:
                self.display()

            elif option == 0:
                return
