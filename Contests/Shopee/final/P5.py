n = int(input())
a = []
for i in range(n):
    x, y = map(int, input().split())
    a.append((x, y))

a.sort(key=lambda x: (x[0], -x[1]))

time = 1
res = 0
for project in a:
    if project[0] < time:
        continue
    time += 1
    res += project[1]
print(res)