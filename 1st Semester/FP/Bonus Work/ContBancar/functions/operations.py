from functions.domain import *


def add_transaction(all_transactions, day, sum, type):
    transaction = create_transaction(day, sum, type)
    all_transactions.append(transaction)


def get_transactions_of_type(all_transactions, type):
    desired_transactions = []
    for i in range(len(all_transactions)):
        if (get_type(all_transactions[i]) == type):
            add_transaction(desired_transactions, get_day(all_transactions[i]), get_sum(all_transactions[i]),
                            get_type(all_transactions[i]))
    return desired_transactions


def get_transactions_with_a_certain_sum_and_day(all_transactions, sum, day):
    desired_transactions = []
    for i in range(len(all_transactions)):
        if (get_sum(all_transactions[i]) > sum and get_day(all_transactions[i]) < day):
            add_transaction(desired_transactions, get_day(all_transactions[i]), get_sum(all_transactions[i]),
                            get_type(all_transactions[i]))
    return desired_transactions


def get_transactions_with_a_sum_greater_than(all_transactions, sum):
    desired_transactions = []
    for i in range(len(all_transactions)):
        if (get_sum(all_transactions[i]) > sum):
            add_transaction(desired_transactions, get_day(all_transactions[i]), get_sum(all_transactions[i]),
                            get_type(all_transactions[i]))
    return desired_transactions


def remove_transactions_at_a_specified_day(all_transactions, day):
    desired_transactions = []
    for i in range(len(all_transactions)):
        if (get_day(all_transactions[i]) != day):
            desired_transactions.append(all_transactions[i])
    all_transactions = desired_transactions
    return all_transactions


def remove_transactions_from_a_time_period(all_transactions, day_start, day_end):
    desired_transactions = []
    for i in range(len(all_transactions)):
        if (get_day(all_transactions[i]) < day_start or get_day(all_transactions[i]) > day_end):
            desired_transactions.append(all_transactions[i])
    all_transactions = desired_transactions
    return all_transactions


def remove_transactions_of_type(all_transactions, type):
    desired_transactions = []
    for i in range(len(all_transactions)):
        if (get_type(all_transactions[i]) != type):
            desired_transactions.append(all_transactions[i])
    all_transactions = desired_transactions
    return all_transactions


def total_sum_of_transactions_of_type(all_transactions, type):
    sum = 0
    for i in range(len(all_transactions)):
        if (get_type(all_transactions[i]) == type):
            sum += get_sum(all_transactions[i])
    return sum


def get_account_balance(all_transactions):
    balance = 0
    for i in range(len(all_transactions)):
        if (get_type(all_transactions[i]) == "intrare"):
            balance += get_sum(all_transactions[i])
        elif (get_type(all_transactions[i]) == "iesire"):
            balance -= get_sum(all_transactions[i])
    return balance


def order_by_sum(all_transactions):
    # TODO: rezolva functia
    # elementul adaugat in noua lista este modificat chiar daca apelez lista initiala
    new_transactions = all_transactions
    ordered_transactions = []
    smax = 0
    smax_index = 0
    for j in range(len(new_transactions)):
        for i in range(len(new_transactions)):
            if (get_sum(new_transactions[i]) > smax):
                smax = get_sum(new_transactions[i])
                smax_index = i
        ordered_transactions.append(new_transactions[smax_index])
        set_sum(new_transactions[smax_index], -1)
        smax = 0
    return ordered_transactions


def eliminate_transactions_of_type(all_transactions, type):
    desired_transactions = []
    for i in range(len(all_transactions)):
        if (get_type(all_transactions[i]) != type):
            desired_transactions.append(all_transactions[i])
    all_transactions = desired_transactions
    return all_transactions


def eliminate_transactions_of_type_with_sum_less_than(all_transactions, type, sum):
    desired_transactions = []
    for i in range(len(all_transactions)):
        if (get_type(all_transactions[i]) != type or get_sum(all_transactions[i]) >= sum):
            desired_transactions.append(all_transactions[i])
    all_transactions = desired_transactions
    return all_transactions