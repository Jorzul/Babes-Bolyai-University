# Given the set of positive integers S, partition this set into two subsets S1 and S2 so that the difference between
# the sum of the elements in S1 and S2 is minimal. For example, for set S = { 1, 2, 3, 4, 5 }, the two subsets could
# be S1 = { 1, 2, 4 } and S2 = { 3, 5 }. Display at least one of the solutions.


# A Recursive Python3 program to solve
# minimum sum partition problem.
import sys


# Returns the minimum value of the
# difference of the two sets.
def menu():
    S = []
    n = int(input("How many elements does the array have?"))
    print("Type the elements: ")
    for i in range(n):
        x = int(input())
        S.append(x)
    print("How would you want to solve the problem?")
    print("1. Using the naive version")
    print("2. Using the dynamic version")
    option = int(input())
    if option == 1:
        naive(S)
    elif option == 2:
        print("The minimum difference between 2 sets is ", dynamic(S, n))


def check(S1, S2):
    S1s = sum(S1)
    S2s = sum(S2)
    if S1s > S2s:
        return S1s - S2s
    if S1s < S2s:
        return S2s - S1s


def dynamic(a, n):
    # Calculate sum of all elements
    su = sum(a)
    # We create a 2d list to store results of sub problems
    matrix = [[0 for i in range(su + 1)] for j in range(n + 1)]
    for i in range(n + 1):
        matrix[i][0] = True
    for j in range(1, su + 1):
        matrix[0][j] = False
    for i in range(1, n + 1):
        for j in range(1, su + 1):
            matrix[i][j] = matrix[i - 1][j]
            if a[i - 1] <= j:
                matrix[i][j] |= matrix[i - 1][j - a[i - 1]]
    diff = sys.maxsize
    for j in range(su // 2, -1, -1):
        if matrix[n][j]:
            diff = su - (2 * j)
            break
    return diff


def naive(S):
    lists = []
    nlists = 0
    minimum_diff = sys.maxsize
    for i in range(len(S)):
        for j in range(i):
            lists.append(S[j: i])
            nlists = nlists + 1
    for i in range(0, len(S) - 1):
        for j in range(i + 1, len(S)):
            diff_of_sums = check(lists[i], lists[j])
            if diff_of_sums < minimum_diff:
                minimum_diff = diff_of_sums
    print("The minimum difference is ", minimum_diff)


menu()
