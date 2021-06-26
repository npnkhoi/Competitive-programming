tc = int(input())
for _ in range(tc):
    n = int(input())
    a = list(map(int, input().split()))
    mark = [False] * n
    for val in a:
        if not mark[val - 1]:
            print(val, end=' ')
            mark[val - 1] = True
    print()