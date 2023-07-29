n = int(input())

def check(x, y):
  for a in range(6, x // 4 + 1):
    b_values = [0, 1, 2, 3, 4] if a == 6 else [a - 2]
    
    for b in b_values:
      rx = x - 4 * a
      ry = y - 4 * b
   
      if rx < 0 or ry < 0:
        continue
      
      if b == 0:
        if rx == 0:
          if ry <= 2 * a:
            return True
        else:
          if ry - rx <= 2 * a and ry - rx >= 2:
            return True
      elif rx > ry:
        if rx - ry <= 2 * b:
          return True
      elif ry > rx:
        if ry - rx <= 2 * a:
          return True
      elif rx == ry:
        if rx != 1:
          return True
  return False

while n > 0:
  x, y = map(int, input().split('-'))
  print("YES" if check(x, y) else "NO")
  n -= 1