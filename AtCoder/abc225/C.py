n, m = map(int, input().split())
last_head = -1
res = True
for i in range(n):
  row = list(map(int, input().split()))
  if i > 0:
    if row[0] - last_head != 7:
      res = False
  last_head = row[0]
  for j in range(0, m-1):
    if row[j+1] - row[j] != 1 or row[j] % 7 == 0:
      res = False

print('Yes' if res else 'No')
