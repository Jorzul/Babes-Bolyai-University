
def set_type(transaction, type):
    transaction["type"] = type


def get_type(transaction):
    return transaction["type"]


def set_sum(transaction, sum):
    transaction["sum"] = sum


def get_sum(transaction):
    return transaction["sum"]


def set_day(transaction, day):
    transaction["day"] = day


def get_day(transaction):
    return transaction["day"]


def create_transaction(day, sum, type):
    return {"day": day, "sum": sum, "type": type}