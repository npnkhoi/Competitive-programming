tc = int(input())
for _ in range(tc):
    n, k = map(int, input().split())
    s = input()
    if s != s[::-1] and k > 0:
        print(2)
    else:
        print(1)