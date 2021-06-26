n = int(input())
for _ in range(n):
    n, k, b = map(int, input().split())

    if n > k * (k + 1) // 2 or n < b * (b + 1) // 2:
        print(-1)
        continue

    base = b * (b + 1) // 2
    rest = n - base
    rem = rest % b
    lower_bound = rest // b

    if b + lower_bound + (rem != 0) > k:
        print(-1)
        continue

    result = list(range(1 + lower_bound, b + 1 + lower_bound))
    for i in range(rem):
        result[b - 1 - i] += 1
    for val in result:
        print(val, end = ' ')
    print()