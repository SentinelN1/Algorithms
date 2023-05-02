from bisect import bisect_left

n = int(input())
s = dict()
cards = list(map(int, input().split()))
for i in cards:
    s[i] = 1

k = int(input())
col = list(map(int, input().split()))
for i in col:
    ind = bisect_left(s, i)
    if ind:
        print(ind - 1)
