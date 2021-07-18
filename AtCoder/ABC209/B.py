n, x = map(int, input().split())
a = list(map(int, input().split()))

if sum(a) - n // 2 <= x:
  print('Yes')
else:
  print('No')