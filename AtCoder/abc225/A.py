s = input()

if s[0] != s[1] and s[1] != s[2] and s[2] != s[0]:
  print(6)
elif s[0] == s[1] and s[1] == s[2]:
  print(1)
else:
  print(3)