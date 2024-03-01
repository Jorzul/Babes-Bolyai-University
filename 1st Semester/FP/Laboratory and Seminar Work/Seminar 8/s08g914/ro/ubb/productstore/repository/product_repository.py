"""

@author: radu

 
"""

"""
class ProductRepository:
    def __init__(self):
        self.__all_products = {}

    def save(self, product):
        if self.__find_by_id(product.get_product_id()) is not None:
            raise ValueError("Duplicate ID.")

        self.__all_products[product.get_product_id()] = product

    def __find_by_id(self, product_id):
        if product_id in self.__all_products:
            return self.__all_products[product_id]

        return None

    def find_all(self):
        return list(self.__all_products.values())

    def update(self, product):
        # todo: check if we have a product with the ID
        self.__all_products[product.get_product_id()] = product

    def delete_by_id(self, product_id):
        # todo: check if ID exists
        del self.__all_products[product_id]
"""


class GenericRepository:
    def __init__(self):
        self.__all_entities = {}

    def save(self, entity):
        if self.__find_by_id(entity_id) is not None:
            raise ValueError("Duplicate ID.")

        self.__all_entities[entity_id] = product

    def __find_by_id(self, entity_id):
        if entity_id in self.__all_entities:
            return self.__all_entities[entity_id]

        return None

    def find_all(self):
        return list(self.__all_entities.values())

    def update(self, entity):
        # todo: check if we have a product with the ID
        self.__all_entities[entity_id] = entity

    def delete_by_id(self, entity_id):
        # todo: check if ID exists
        del self.__all_products[product_id]
