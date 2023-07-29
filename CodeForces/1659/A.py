tc = int(input())
for _ in range(tc):
  n, r, b = map(int, input().split())
  if r <= b:
    cnt = [r, b]
    char = ['R', 'B']
  else:
    cnt = [b, r]
    char = ['B', 'R']

  seg = (cnt[1] + cnt[0]) // (cnt[0] + 1)
  for i in range(cnt[0]):
    cnt[1] -= seg
    for _ in range(seg):
      print(char[1], end='')
    print(char[0], end='')
  # print(cnt, seg)
  for i in range(cnt[1]):
    print(char[1], end='')
  print()