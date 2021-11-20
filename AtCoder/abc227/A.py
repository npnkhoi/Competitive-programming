n, k, a = map(int, input().split())
res = (a + k - 1) % n
if res == 0:
  res = n
print(res)