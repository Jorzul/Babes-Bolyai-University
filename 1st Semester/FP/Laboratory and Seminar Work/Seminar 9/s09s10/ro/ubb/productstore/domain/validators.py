"""

@author: radu

 
"""


class ProductValidator:
    @staticmethod
    def validate(product):
        if product.name == "":
            raise ValueError("name can not be empty")
        # todo: other validations


class OrderValidator:
    @staticmethod
    def validate(order):
        if order.name == "":
            raise ValueError("name can not be empty")
        #todo: other validations
