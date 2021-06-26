import math
n = int(input())
b = int(input())
list_ball = []
total = 0
for i in range (b):
    s,d = map(int, input().split())
    c = 2*d*math.pi
    list_ball.append((c,s))
list_ball.sort()
remain = n

for each in list_ball:
    c,s = each
    x = remain // c
    if x>=s:
        total += s
        remain -= c*s
    else:
        total += x
        break
print(int(total))