n, k = map(int, input().split())
c = list(map(int, input().split()))

count = {}
distinct = 0

def update(val, delta, distinct):
  count.setdefault(val, 0)
  if count[val] == 0:
    distinct += 1
  count[val] += delta
  if count[val] == 0:
    distinct -= 1
  return distinct

for i in range(k):
  distinct = update(c[i], +1, distinct)

res = distinct
for i in range(k, n):
  distinct = update(c[i], +1, distinct)
  distinct = update(c[i-k], -1, distinct)
  res = max(res, distinct)

print(res)
