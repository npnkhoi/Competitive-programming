n, a, x, y = map(int, input().split())

res = min(n, a) * x

if n > a:
  res += (n - a) * y

print(res)