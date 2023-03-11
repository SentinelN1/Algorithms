maxArea = 0
hist = list(map(int, input().split()))
n = hist[0]
for i in range(1, n + 1):
    tmp = hist[i]
    for j in range(i, 0, -1):
        tmp = min(tmp, hist[j])
        maxArea = max(maxArea, tmp * (i - j + 1))
print(maxArea)
