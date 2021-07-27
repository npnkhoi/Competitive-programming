s = []
t = ['H', '2B', '3B', 'HR']
mark = [False] * 4
for i in range(4):
    s.append(input())
    for j in range(4):
        if s[-1] == t[j]:
            mark[j] = True
result = True
for value in mark:
    if not value:
        result = False
print('Yes' if result else 'No')