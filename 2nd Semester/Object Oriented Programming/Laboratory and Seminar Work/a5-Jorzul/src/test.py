
def lul(arr, n):
    las = [[0 for i in range(2)] for j in range(n)]
    for i in range(n):
        las[i][0] = 1
        las[i][1] = 1
    res = 1
    for i in range(1, n):
        for j in range(0, i):
            if arr[j] < arr[i] and las[i][0] < las[j][1] + 1:
                las[i][0] = las[j][1] + 1
            if arr[j] > arr[i] and las[i][1] < las[j][0] + 1:
                las[i][1] = las[j][0] + 1
            print("i= ", i, " j= ", j)
            for row in las:
                print(' '.join([str(elem) for elem in row]))
        if res < max(las[i][0], las[i][1]):
            res = max(las[i][0], las[i][1])
    return res


arr = [10, 22, 9, 33, 49, 50, 31, 60]
n = len(arr)

print("Length is: ", lul(arr, n))
