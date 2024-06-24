s = str(input())

m = -1
M = -1

for (i, c) in enumerate(s):
    if (m == -1 or ord(s[m]) > ord(c)) or (ord(s[m]) == ord(c) and abs(M - i) < abs(M - m)):
        m = i

    if (M == -1 or ord(s[M]) < ord(c)) or (ord(s[M]) == ord(c) and abs(m - i) < abs(M - m)):
        M = i

print(s[min(m, M):(max(m, M) + 1)])
