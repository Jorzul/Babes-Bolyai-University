# The sequence a = a1, ..., an with distinct integer numbers is given.
# Determine all subsets of elements having the sum divisible by a given n.
import random


def menu():
    n = int(input('n= '))
    a = []
    print('Do you want to manually type the elements of the list?')
    print('1. Yes indeed.')
    print('2. No, I dont have time for that')
    ran = int(input())
    if ran == 1:
        print('Type the elements of the list: ')
        for i in range(0, n):
            x = int(input())
            a.append(x)
    if ran == 2:
        for i in range(0, n):
            x = random.randint(1, n)
            a.append(x)
        print('The list: ', a)
    print('What version do you want the program to be solved?')
    print('1. Recursive.')
    print('2. Iterative')
    ran = int(input())
    if ran == 1:
        recursive(a)
    if ran == 2:
        iterative(a)


# It returns the sum of all the elements from a given A list
def suma(A):
    s = int(0)
    for i in range(0, len(A)):
        s = s + A[i]
    return s


def backtracking(A, subset, k):
    s = suma(subset)
    if s == len(A):
        print(subset)
    for i in range(k, len(A)):
        subset.append(A[i])
        backtracking(A, subset, i + 1)
        subset.pop(-1)
    return


# Begins the recursive version in which the program can be solved
def recursive(A):
    subset = []
    k = 0
    backtracking(A, subset, k)


# This function starts the iterative version in which the program can be solved
def iterative(A):
    lists = []
    nlists = 0
    for i in range(len(A) + 1):
        for j in range(i):
            lists.append(A[j: i])
            nlists = nlists + 1
    for i in range(1, nlists):
        s = suma(lists[i])
        if s == len(A):
            print(lists[i])


menu()
