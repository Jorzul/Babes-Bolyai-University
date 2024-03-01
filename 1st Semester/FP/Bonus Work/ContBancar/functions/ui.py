from functions.operations import *


def ui_add_transaction(all_transactions):
    day = int(input("day="))
    sum = int(input("sum="))
    type = input("type=")
    add_transaction(all_transactions, day, sum, type)


def print_options():
    print("1.Add transaction\n"
          "2.Print all transactions\n"
          "3.Print all transactions of type\n"
          "4.Print transactions with a sum greater than a given number and before a certain day\n"
          "5.Print transactions with a sum greater than a given number\n"
          "6.Remove transactions at a specified date\n"
          "7.Remove transactions from a specified time period\n"
          "8.Remove transactions of a certain type\n"
          "9.Print transactions ordered by sum\n"
          "10.Eliminate transactions of a certain type\n"
          "11.Eliminate transactions of a certain type with a sum lower than a given number\n"
          "12.Print total sum of transactions with a certain type\n"
          "13.Print account balance\n"
          "u.Undo\n"
          "x.Exit")


def print_all_transactions(all_transactions):
    print(all_transactions)


def print_transactions_of_type(all_transactions):
    type = input("Transaction Type:")
    desired_transactions = get_transactions_of_type(all_transactions, type)
    print(desired_transactions)


def print_transactions_with_a_certain_sum_and_day(all_transactions):
    sum = int(input("Sum:"))
    day = int(input("Day:"))
    desired_transactions = get_transactions_with_a_certain_sum_and_day(all_transactions, sum, day)
    print(desired_transactions)


def print_transactions_with_a_sum_greater_than(all_transactions):
    sum = int(input("Sum:"))
    desired_transactions = get_transactions_with_a_sum_greater_than(all_transactions, sum)
    print(desired_transactions)


def scan_remove_transactions_at_a_specified_day(all_transactions):
    day = int(input("Day:"))
    all_transactions[:] = remove_transactions_at_a_specified_day(all_transactions, day)


def scan_remove_transactions_from_a_time_period(all_transactions):
    day_start = int(input("Starting day:"))
    day_end = int(input("Last day:"))
    all_transactions[:] = remove_transactions_from_a_time_period(all_transactions, day_start, day_end)


def scan_remove_transactions_of_type(all_transactions):
    type = input("Type:")
    all_transactions[:] = remove_transactions_of_type(all_transactions, type)


def print_order_by_sum(all_transactions):
    ordered_transactions = order_by_sum(all_transactions)
    print(ordered_transactions)


def scan_eliminate_transactions_of_type(all_transactions):
    type = input("Type:")
    all_transactions[:] = eliminate_transactions_of_type(all_transactions, type)


def scan_eliminate_transactions_of_type_with_sum_less_than(all_transactions):
    type = input("Type:")
    sum = int(input("Sum:"))
    all_transactions[:] = eliminate_transactions_of_type_with_sum_less_than(all_transactions, type, sum)


def ui_total_sum_of_transactions_of_type(all_transactions):
    type=input("Type:")
    print("Sum=",total_sum_of_transactions_of_type(all_transactions,type))

def ui_get_account_balance(all_transactions):
    print("Account Balance:",get_account_balance(all_transactions))

