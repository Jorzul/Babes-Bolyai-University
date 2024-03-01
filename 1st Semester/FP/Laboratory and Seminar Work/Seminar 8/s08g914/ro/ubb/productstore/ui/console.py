"""

@author: radu

 
"""


class Console:
    def __init__(self, product_service):
        self.__product_service = product_service

    def run_console(self):
        # todo: Implement menu UI
        self.__add_products()
        self.__print_all_products()

    def __add_products(self):
        self.__product_service.add_product(1, "prod1", 10)
        self.__product_service.add_product(2, "prod2", 20)

    def __print_all_products(self):
        print(self.__product_service.get_all_products())  # todo: ????
