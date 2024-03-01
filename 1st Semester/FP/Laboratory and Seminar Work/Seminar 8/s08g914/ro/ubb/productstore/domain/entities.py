"""

@author: radu

 
"""
from dataclasses import dataclass


@dataclass
class Product:
    id: int
    name: str
    price: int


"""
class Product:
    def __init__(self, product_id, name, price):
        self.__product_id = product_id
        self.__name = name
        self.__price = price

    def get_product_id(self):
        return self.__product_id

    def get_name(self):
        return self.__name

    def get_price(self):
        return self.__price

    def set_product_id(self, product_id):
        self.__product_id = product_id

    def set_name(self, name):
        self.__name = name

    def set_price(self, price):
        self.__price = price

    def __str__(self):
        return f"Product ID: {self.__product_id} \nName: {self.__name} \nPrice: {self.__price}"
"""

class Order:
    id: int
    product_id: int
    quantity: int
