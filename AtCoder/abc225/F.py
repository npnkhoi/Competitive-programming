n, k = map(int, input().split())
s = []
for _ in range(n):
  s.append(input())
s.sort()
res = ''

while k > 0:
  # print(s)
  # Get range
  r = 0
  while r + 1 < len(s) and s[r+1].startswith(s[0]):
    r += 1
  
  # Find best
  best = 0
  if k > 1:
    for i in range(1, r+1):
      if s[i] + s[best] < s[best] + s[i]:
        best = i

  # Update result
  k -= 1
  res += s[best]
  s.pop(best)

print(res)

