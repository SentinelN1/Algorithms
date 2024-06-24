p, n, k = map(int, input().split())

themes = []
for i in range(p):
    themes.append(str(input()))

ids = list(map(int, input().split()))
# print(themes, ids)

total = 0
tmp = {}

for i in range(p):
    theme = themes[i]
    id = ids[i]
    tmp.setdefault(theme, [])
    tmp[theme].append(id)

    if (total < n and len(tmp[theme]) <= k):
        print(f'{theme} #{id}')
        total += 1
