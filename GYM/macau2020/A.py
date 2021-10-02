n = int(input())
res = 1e9
for i in range(1, n + 1):
  res *= i * i
for i in range(n):
  res /= n
print("{:.10f}".format(res))