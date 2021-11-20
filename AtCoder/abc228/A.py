s, t, x = map(int, input().split())
if s < t:
  print('Yes' if (s <= x and x < t) else 'No')
else:
  print('No' if (t <= x and x < s) else 'Yes')