n, m = map(int, input().split())

matrix = []

for i in range(n):
    tmp = list(map(int, input().split()))
    matrix.append(tmp)

for j in range(m):
    for i in range(n - 1, -1, -1):
        print(matrix[i][j], end=' ')
    print('')
