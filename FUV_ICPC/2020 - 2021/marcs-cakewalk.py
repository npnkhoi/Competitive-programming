n = int(input())
calorie = list(map(int, input().split()))
calorie.sort()
res = 0
length = len(calorie)
for i in range(length):
    res += (2 ** i) * calorie[length - i - 1]
print(res)