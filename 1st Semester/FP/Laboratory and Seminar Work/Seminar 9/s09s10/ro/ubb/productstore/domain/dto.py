from dataclasses import dataclass


@dataclass
class OrderDto:
    product_name: str
    quantity: int
    cost: int


class OrderAssembler:
    @staticmethod
    def create_order_dto(product, order):
        order_dto = OrderDto(product.name, order.quantity, product.price * order.quantity)
        return order_dto
