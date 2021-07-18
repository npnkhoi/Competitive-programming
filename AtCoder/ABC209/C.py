n = int(input())
a = list(map(int, input().split()))
a.sort()


MOD = 10**9 + 7
result = 1
for i in range(n):
  if a[i] <= i:
    result = 0
  else:
    result = result * (a[i] - i) % MOD
print(result)
