class Taxi:
    def __init__(self, id: int, fare: int, x: int, y: int):

        self.__id = id
        self.__fare = fare
        self.__x = x
        self.__y = y

    @property
    def id(self):
        return self.__id

    @property
    def fare(self):
        return self.__fare

    @property
    def x(self):
        return self.__x

    @property
    def y(self):
        return self.__y

    @fare.setter
    def fare(self, new_fare):
        self.__fare = new_fare

    @x.setter
    def x(self, new_x):
        self.__x = new_x

    @y.setter
    def y(self, new_y):
        self.__y = new_y

    def __str__(self):
        return "id:" + str(self.id) + ",fare:" + str(self.fare) + ",(" + str(self.x) + ", " + str(self.y) + ")"
