# 7 and 13
# Write the implementation for A5 in this file
#
import cmath


#
# Write below this comment 
# Functions to deal with complex numbers -- list representation
# -> There should be no print or input statements in this section 
# -> Each function should do one thing only
# -> Functions communicate using input parameters and their return values
def create_number(real, imaginary):
    z = [real, imaginary]
    return z


def set_real(z, real):
    z[0] = real


def set_imaginary(z, imaginary):
    z[1] = imaginary


#
# Write below this comment 
# Functions to deal with complex numbers -- dict representation
# -> There should be no print or input statements in this section 
# -> Each function should do one thing only
# -> Functions communicate using input parameters and their return values
def to_string(z):
    real = get_real(z)
    imaginary = get_imaginary(z)
    s = f'{real}'
    if imaginary != 0:
        s = s + f' + {imaginary}i'
    return s


def get_real(z):
    return z[0]


def get_imaginary(z):
    return z[1]


#
# Write below this comment 
# Functions that deal with subarray/subsequence properties
# -> There should be no print or input statements in this section 
# -> Each function should do one thing only
# -> Functions communicate using input parameters and their return values
def longest_alternating_sub(arr):
    LAS = [[0 for _ in range(2)] for _ in range(len(arr))]
    for i in range(len(arr)):
        LAS[i][0] = 1
        LAS[i][1] = 1
    result = 1
    for i in range(1, len(arr)):
        for j in range(0, i):
            if arr[j] < arr[i] and LAS[i][0] < LAS[j][1] + 1:
                LAS[i][0] = LAS[j][1] + 1
            if arr[j] > arr[i] and LAS[i][1] < LAS[j][0] + 1:
                LAS[i][1] = LAS[j][0] + 1
        if result < max(LAS[i][0], LAS[i][1]):
            result = max(LAS[i][0], LAS[i][1])
    return result


def return_Longest_Mountain_list(List):
    start = -1
    end = -1
    k = 0
    List_for_now = []
    longest_mountain_list = []
    length_of_longest_mountain = 0
    if len(List) < 3:
        return longest_mountain_list
    for i in range(len(List) - 1):
        if get_real(List[i + 1]) > get_real(List[i]):
            # If the next element is increasing but we are in a mountain subset, we restart
            if end != -1:
                end = -1
                start = -1
                k = 0
                List_for_now = []
            if start == -1:
                start = i
            z = create_number(get_real(List[i]), get_imaginary(List[i]))
            List_for_now.append(z)
            k = k + 1
        else:
            if get_real(List[i + 1]) < get_real(List[i]):
                if start != 1:
                    end = i + 1
                    z = create_number(get_real(List[i]), get_imaginary(List[i]))
                    List_for_now.append(z)
                    k = k + 1
                    z = create_number(get_real(List[i+1]), get_imaginary(List[i+1]))
                    List_for_now.append(z)
                if end != -1 and start != -1:
                    if length_of_longest_mountain < end - start + 1:
                        length_of_longest_mountain = end - start + 1
                        longest_mountain_list = list(List_for_now)
            else:
                start = -1
                end = -1
    return longest_mountain_list


def return_Longest_Mountain_list_length(List):
    start = -1
    end = -1
    length_of_longest_mountain = 0
    if len(List) < 3:
        return 0
    for i in range(len(List) - 1):
        if get_real(List[i + 1]) > get_real(List[i]):
            # If the next element is increasing but we are in a mountain subset, we restart
            if end != -1:
                end = -1
                start = -1
            if start == -1:
                start = i
        else:
            if get_real(List[i + 1]) < get_real(List[i]):
                if start != 1:
                    end = i + 1
                if end != -1 and start != -1:
                    if length_of_longest_mountain < end - start + 1:
                        length_of_longest_mountain = end - start + 1
            else:
                start = -1
                end = -1
    if end != -1 and start != -1 and length_of_longest_mountain < end - start + 1:
        length_of_longest_mountain = end - start + 1
    return length_of_longest_mountain


def Max(a, b):
    if a > b:
        return a
    else:
        return b


def reset_list_for_now(A, List):
    for i in range(len(List) // 2):
        A.append(0)


#
# Write below this comment 
# UI section
# Write all functions that have input or print statements here
# Ideally, this section should not contain any calculations relevant to program functionalities


def display_7(List):
    longest_mountain_list = []
    for i in range(len(List)):
        longest_mountain_list.append(0)
    longest_mountain_list = return_Longest_Mountain_list(List)
    length_of_longest_mountain = return_Longest_Mountain_list_length(List)
    print("The length for the longest mountain is: ", length_of_longest_mountain)
    display_list(longest_mountain_list)


def display_13(List):
    array_of_modulus_numbers = []
    for i in range(len(List)):
        y = cmath.sqrt((get_real(List[i])) ** 2 + (get_imaginary(List[i])) ** 2)
        array_of_modulus_numbers.append(int(y.real))
    print("The list of modulus numbers is: ")
    print(array_of_modulus_numbers)
    print("The longest length of alternating numbers: ", longest_alternating_sub(array_of_modulus_numbers))


def read_list():
    c_list = []
    n = int(input("The number of elements is: "))
    for i in range(n):
        r = int(input("Real part: "))
        img = int(input("Imaginary part: "))
        z = create_number(r, img)
        c_list.append(z)
    return c_list


def display_list(c_list):
    """
    This function displays the current list if it has elements, otherwise it displays a prompt.
    param c_list: list of complex numbers
    """
    if len(c_list) == 0:
        print("No list exists.")
        return
    print("The elements are: ")
    for z in c_list:
        print(to_string(z))


def ui():
    options = "\nThe options:\nRead a list of complex numbers: 1\nDisplay list: 2\nDisplay with property: 3\nExit: 4\n"
    c_list = list()
    exited = False
    while not exited:
        command = int(input(options))
        match command:
            case 1:
                c_list = read_list()
            case 2:
                display_list(c_list)
            case 3:
                print("Problem 7:")
                display_7(c_list)
                print("Problem 13:")
                display_13(c_list)
            case 4:
                print("The program will be exited.")
                exited = True
            case _:
                print("This option does not exist.")


if __name__ == "__main__":
    ui()
