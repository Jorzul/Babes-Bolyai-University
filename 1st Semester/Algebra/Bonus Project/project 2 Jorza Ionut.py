from itertools import permutations


def get_operation_table(n, operation):
    """
    Returns the operation table for a given operation
    on a set of size n.
    """
    table = {}
    elements = [i + 1 for i in range(n)]
    for i in elements:
        for j in elements:
            table[(i, j)] = operation(i, j)
    return table


def associative_operations(n):
    """
    Returns the number of associative operations and
    the operation tables for a set of size n.
    """
    operations = 0
    for operation in permutations(range(1, n + 1)):
        is_associative = True
        table = get_operation_table(n, lambda x, y: operation[x - 1])
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                for k in range(1, n + 1):
                    if table[(table[(i, j)], k)] != table[(i, table[(j, k)])]:
                        is_associative = False
                        break
                if not is_associative:
                    break
            if not is_associative:
                break
        if is_associative:
            operations += 1
            print("Operation table for operation ", operation, ":")
            print(table)
    return operations


n = int(input("Enter a non-zero natural number: "))
print("Number of associative operations: ", associative_operations(n))
