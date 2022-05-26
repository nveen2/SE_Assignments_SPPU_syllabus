
def uppertriangular(n, m, l):
    if n != m:
        return False
    elif n == m:
        for i in range(0, n):
            f = True
            for j in range(0, m):
                if l[i][j] != 0 and j < i:
                    f = False
                    break
            if f == False:
                return False
    return True


def diagonalsum(n, m, l):
    if n != m:
        print("A non-square matrix's diagonal sum cannot be calculated")
        return
    elif n == m:
        sum = 0
        for i in range(0, n):
            sum += l[i][i]
        for i in range(0, n):
            sum += l[i][n - i - 1]
        return sum


def transpose( n, m, l):
    _l = []
    for i in range(0, m):
        il = []
        for j in range(0, n):
            il.append(l[j][i])
        _l.append(il)
    for i in range(0, m):
        for j in range(0, n):
            if j == n - 1:
                print(_l[i][j], end="\n")
            else:
                print(_l[i][j], end=" ")


def addition(n, m, l1, l2):
    _l = []
    for i in range(0, n):
        row = []
        for j in range(0, m):
            row.append(l1[i][j] + l2[i][j])
        _l.append(row)

    for i in range(0, n):
        for j in range(0, m):
            if j == m - 1:
                print(_l[i][j], end="\n")
            else:
                print(_l[i][j], end=" ")


def multiplication(n, m, an, am, l1, l2):
    _l = []
    for i in range(0, n):
        row = []
        for j in range(0, am):
            sum = 0
            for k in range(0, m):
                sum += l1[i][k] * l2[k][j]
            row.append(sum)
        _l.append(row)
    for i in range(0, n):
        for j in range(0, am):
            if j == am - 1:
                print(_l[i][j], end="\n")
            else:
                print(_l[i][j], end=" ")


def saddlepoints(n, m, l):
    row_min = []
    for i in range(0, n):
        min = l[i][0]
        for j in range(1, m):
            if (min > l[i][j]):
                min = l[i][j]
        row_min.append(min)
    col_max = []
    for i in range(0, m):
        max = -1
        for j in range(0, n):
            if max < l[j][i]:
                max = l[j][i]
        col_max.append(max)
    flag = False
    for i in range(0, n):
        for j in range(0, m):
            if row_min[i] == l[i][j] and col_max[j] == l[i][j]:
                flag = True
                print(i, end=" ")
                print(j, end="\n")
    if flag == False:
        print("No saddle points")


n = int(input())
m = int(input())
list = []
for i in range(0, n):
    row = []
    for j in range(0, m):
        row.append(int(input()))
    list.append(row)
print(uppertriangular(n, m, list))
print(diagonalsum(n, m, list))
transpose(n, m, list)
an = int(input())
am = int(input())
alist = []
for i in range(0, an):
    row = []
    for j in range(0, am):
        row.append(int(input()))
    alist.append(row)
if n == an and m == am:
    addition(n, m, list, alist)
else:
    print("Addition of matrices is only possible when the given matrices are of same order")

if m == an:
    multiplication(n, m, an, am, list, alist)
else:
    print("Multiplication of such matrix is not possible")

saddlepoints(n, m, list)

row = int(input("Enter number of rows : "))
col = int(input("Enter number of columns : "))
matrix = [row][col]
for i in range(row):
    for j in range(col):
        matrix[i][j] = int(input())
