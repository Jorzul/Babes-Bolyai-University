import random


def generate_new_number():
    # This function generates a new random secret number. (The computer number)
    while True:
        number = random.randint(1000, 9999)
        if check_for_distinct_digits(number) & check_for_first_digit_non_zero(number):
            break
    return number


def check_for_distinct_digits(n):
    """
    This function checks if the computer number or the human number is a valid number.
    (It contains only distinct digits)
    """

    n = int(n)
    list_of_numbers = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    while n > 0:
        list_of_numbers[int(n % 10)] = list_of_numbers[int(n % 10)] + 1
        n = n // 10
    for i in range(len(list_of_numbers)):
        if list_of_numbers[i] > 1:
            return False
    return True


def check_for_first_digit_non_zero(n):
    """
     This function checks if the computer number or the human number is a valid number.
     (The first digit is not 0)
    """
    n = n // 1000
    if n == 0:
        return False
    else:
        return True


def check_for_codes_and_runners(secret_number, human_number):
    """

    :param secret_number: the number selected by the calculator
    :param human_number: the number selected by the player
    :return: the number of codes and runners

    In here we check how many codes and runners we got.
    We save the position of each digit of the secret number and the human number, and then we check if the positions
    are equal or atleast if the digits are part of both numbers.
    """
    codes = int(0)
    runners = int(0)
    secret_number_list = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    human_number_list = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    position = int(4)

    while secret_number:
        secret_number_list[int(secret_number % 10)] = position
        human_number_list[int(human_number % 10)] = position
        position = position - 1
        human_number = human_number // 10
        secret_number = secret_number // 10

    for i in range(0, 9):
        if int(secret_number_list[i]) > 0 and secret_number_list[i] == human_number_list[i]:
            codes = codes + 1
        elif secret_number_list[i] > 0 and human_number_list[i] > 0:
            runners = runners + 1

    return codes, runners


def test_check_for_codes_and_runners(secret_number, human_number):
    """

    :param secret_number: the number selected by the calculator
    :param human_number: the number selected by the player
    :return: True if the function works as intended, False otherwise
    """
    try:
        codes = int(0)
        runners = int(0)
        secret_number_list = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        human_number_list = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        position = int(4)

        while secret_number:
            secret_number_list[int(secret_number % 10)] = position
            human_number_list[int(human_number % 10)] = position
            position = position - 1
            human_number = human_number // 10
            secret_number = secret_number // 10

        for i in range(0, 9):
            if int(secret_number_list[i]) > 0 and secret_number_list[i] == human_number_list[i]:
                codes = codes + 1
            elif secret_number_list[i] > 0 and human_number_list[i] > 0:
                runners = runners + 1

        return True
    except ValueError:
        return False
