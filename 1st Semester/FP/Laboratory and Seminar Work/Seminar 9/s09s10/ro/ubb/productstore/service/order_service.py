"""

@author: radu

"""
from functools import reduce

from ro.ubb.productstore.domain.dto import OrderAssembler


class OrderService:
    def __init__(self, order_repository, product_repository):
        self.__order_repository = order_repository
        self.__product_repository = product_repository

    def filter_by_cost(self, cost: int):
        order_dtos = self.__create_order_dtos()
        # result = (order_dto for order_dto in order_dtos if order_dto.cost > cost)

        result = list(filter(lambda order_dto: order_dto.cost > cost, order_dtos))

        return result

    def __create_order_dtos(self):
        orders = self.__order_repository.find_all()
        order_dtos = []
        for order in orders:
            product = self.__product_repository.find_by_id(order.product_id)
            order_dtos.append(OrderAssembler.create_order_dto(product, order))

        return order_dtos

    def compute_cost(self):
        order_dtos = self.__create_order_dtos()
        total_cost = 0
        # for order_dto in order_dtos:
        #     total_cost += order_dto.cost

        total_cost = reduce(lambda x, order_dto: x + order_dto.cost, order_dtos, 0)
