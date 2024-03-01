from src.functions import generate_new_number, check_for_distinct_digits, check_for_first_digit_non_zero, \
    check_for_codes_and_runners, test_check_for_codes_and_runners


def cheat_code(secret_number):
    """
    This is the cheat code. The game automatically exits and shows the correct number
    """

    print("Cheat code activated")
    print("The number was", secret_number)


def run_console():
    secret_number = int(generate_new_number())
    while True:
        try:
            human_number = int(input(">"))

            if human_number == secret_number:
                print(human_number, "was the secret number. You won")
                break

            if not check_for_distinct_digits(human_number) or not check_for_first_digit_non_zero(human_number):
                print("Game Over")
                break

            if human_number > 9999 or human_number < 1000:
                print("Enter a 4-digit number")
                continue

            if human_number == 8086:
                cheat_code(secret_number)
                break

            if test_check_for_codes_and_runners(secret_number, human_number):
                codes, runners = check_for_codes_and_runners(secret_number, human_number)
                print("Computer reports ", codes, " codes and ", runners, " runners")

        except ValueError:
            print("Enter a 4-digit number")


run_console()
