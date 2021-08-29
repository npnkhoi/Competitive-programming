n = int(input())
for k in range(100):
  if 2 ** k > n:
    print(k - 1)
    break