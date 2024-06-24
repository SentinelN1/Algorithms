def solve(a, b, c):
    if (a + b + c == 1):
        return True

    dx = min(b, c)
    dy = min(a, c)
    dz = min(a, b)

    if (dx > 0 and dx == max(dx, dy, dz)):
        return solve(a + dx, b - dx, c - dx)
    elif (dy > 0 and dy == max(dx, dy, dz)):
        return solve(a - dy, b + dy, c - dy)
    elif (dz > 0 and dz == max(dx, dy, dz)):
        return solve(a - dz, b - dz, c + dz)


n = int(input())
for i in range(n):
    a, b, c = map(int, input().split())
    if (solve(a, b, c)):
        print("Yes")
    else:
        print("No")
