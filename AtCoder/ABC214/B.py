s, t = map(int, input().split())
cnt = 0
for a in range(0, s+1):
  for b in range(0, s - a + 1):
    for c in range(0, s - a - b + 1):
      if a * b * c <= t:
        cnt += 1

print(cnt)
