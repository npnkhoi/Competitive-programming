x = input()
n = len(x)

s = 0
res = 0
for i in range(n):
  s += ord(x[i]) - ord('0')
  res += s * (10 ** (n - i - 1))

print(res)