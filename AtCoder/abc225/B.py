n = int(input())
deg = [0] * (n+1)
for _ in range(n-1):
  a, b = map(int, input().split())
  deg[a] += 1
  deg[b] += 1

res = False
for i in range(1, n+1):
  if deg[i] == n-1:
    res = True
print('Yes' if res else 'No')