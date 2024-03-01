# from functions.operations import *
from functions.ui import *
from functions.domain import *


#################################### tests ############################


def setup():
    all_transactions = [create_transaction(1, 50, "intrare"), create_transaction(5, 100, "iesire")]
    return all_transactions


def test_add_transaction():
    all_transactions = setup()
    add_transaction(all_transactions, 3, 10, "iesire")
    assert (len(all_transactions) == 3)
    assert (get_day(all_transactions[2]) == 3)
    assert (get_sum(all_transactions[2]) == 10)
    assert (get_type(all_transactions[2]) == "iesire")


def test_get_transactions_of_type():
    all_transactions = setup()
    desired_transactions = get_transactions_of_type(all_transactions, "intrare")
    assert (len(desired_transactions) == 1)
    assert (get_type(desired_transactions[0]) == "intrare")


def test_get_transactions_with_a_certain_sum_and_day():
    all_transactions = setup()
    desired_trasactions = get_transactions_with_a_certain_sum_and_day(all_transactions, 70, 10)
    assert (len(desired_trasactions) == 1)
    assert (get_sum(desired_trasactions[0]) == 100)
    assert (get_day(desired_trasactions[0]) == 5)


def test_get_transactions_with_a_sum_greater_than():
    all_transactions = setup()
    desired_transactions = get_transactions_with_a_sum_greater_than(all_transactions, 70)
    assert (len(desired_transactions) == 1)
    assert (get_sum(desired_transactions[0]) == 100)


def test_remove_transactions_at_a_specified_day():
    all_transactions = setup()
    all_transactions = remove_transactions_at_a_specified_day(all_transactions, 5)
    assert (len(all_transactions) == 1)
    assert (get_day(all_transactions[0]) == 1)
    assert (get_sum(all_transactions[0]) == 50)
    assert (get_type(all_transactions[0]) == "intrare")


def test_remove_transactions_from_a_time_period():
    all_transactions = setup()
    all_transactions = remove_transactions_from_a_time_period(all_transactions, 4, 6)
    assert (len(all_transactions) == 1)
    assert (get_day(all_transactions[0]) == 1)
    assert (get_sum(all_transactions[0]) == 50)
    assert (get_type(all_transactions[0]) == "intrare")


def test_remove_transactions_of_type():
    all_transactions = setup()
    all_transactions = remove_transactions_of_type(all_transactions, "iesire")
    assert (len(all_transactions) == 1)
    assert (get_day(all_transactions[0]) == 1)
    assert (get_sum(all_transactions[0]) == 50)
    assert (get_type(all_transactions[0]) == "intrare")


def test_total_sum_of_transactions_with_type():
    all_transactions = setup()
    sum = total_sum_of_transactions_of_type(all_transactions, "intrare")
    assert (sum == 50)
    sum = total_sum_of_transactions_of_type(all_transactions, "iesire")
    assert (sum == 100)


def test_get_account_balance():
    all_transactions = setup()
    balance = get_account_balance(all_transactions)
    assert (balance == -50)


def test_eliminate_transactions_of_type():
    all_transactions = setup()
    all_transactions = eliminate_transactions_of_type(all_transactions, "iesire")
    assert (len(all_transactions) == 1)
    assert (get_day(all_transactions[0]) == 1)
    assert (get_sum(all_transactions[0]) == 50)
    assert (get_type(all_transactions[0]) == "intrare")


def test_eliminate_transactions_of_type_with_sum_less_than():
    all_transactions = setup()
    all_transactions = eliminate_transactions_of_type_with_sum_less_than(all_transactions, "iesire", 150)
    assert (len(all_transactions) == 1)
    assert (get_day(all_transactions[0]) == 1)
    assert (get_sum(all_transactions[0]) == 50)
    assert (get_type(all_transactions[0]) == "intrare")


def test_all():
    # 1 3 4 5 6 7 8 9 10 11? 12 13
    test_add_transaction()
    test_get_transactions_of_type()
    test_get_transactions_with_a_certain_sum_and_day()
    test_get_transactions_with_a_sum_greater_than()
    test_total_sum_of_transactions_with_type()
    test_get_account_balance()
    test_remove_transactions_at_a_specified_day()
    test_remove_transactions_from_a_time_period()
    test_remove_transactions_of_type()
    test_eliminate_transactions_of_type()
    test_eliminate_transactions_of_type_with_sum_less_than()


################################## main ################################

def run_menu():
    options = {1: ui_add_transaction, 2: print_all_transactions,
               3: print_transactions_of_type, 4: print_transactions_with_a_certain_sum_and_day,
               5: print_transactions_with_a_sum_greater_than, 6: scan_remove_transactions_at_a_specified_day,
               7: scan_remove_transactions_from_a_time_period, 8: scan_remove_transactions_of_type,
               9: print_order_by_sum, 10: scan_eliminate_transactions_of_type,
               11: scan_eliminate_transactions_of_type_with_sum_less_than, 12: ui_total_sum_of_transactions_of_type,
               13: ui_get_account_balance}
    all_transactions = []
    old_transactions = all_transactions
    while True:
        print_options()
        opt = input("option=")
        if opt == "x":
            break
        if opt == "u":
            all_transactions[:]=old_transactions
            continue
        old_transactions = all_transactions
        opt = int(opt)
        options[opt](all_transactions)


if __name__ == '__main__':
    test_all()
    run_menu()
