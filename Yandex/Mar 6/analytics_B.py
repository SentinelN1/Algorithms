n, s = map(int, input().split())

if (s >= n):
    print('INF')
    exit()

t = []
for i in range(n):
    ti = int(input())
    t.append(ti)

t.sort()
ans = None
for i in range(n - s):
    if (ans is None or ans > t[i + s] - t[i]):
        ans = t[i + s] - t[i]

if (ans == 0):
    print('Impossible')
    exit()

print(ans)
