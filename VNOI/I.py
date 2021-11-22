n = int(input())

def check(x, y):
  for a in range(6, x // 4 + 1):
    for b in range(y // 4 + 1):
      if a == 6:
        if b > 4:
          continue
      else:
        if b != a - 2:
          continue 

      # print(f'consider {a} {b}')
      rx = x - 4 * a
      ry = y - 4 * b
      if ry > rx and ry - rx  <= 2 * a:
        return True
      if rx > ry and rx - ry  <= 2 * b:
        return True
      if rx == ry:
        return True
  return False

while n > 0:
  x, y = map(int, input().split('-'))
  print("YES" if check(x, y) else "NO")
  n -= 1