p = list(map(int,  input().split()))
for x in p:
  print(chr(x + ord('a') - 1), end='')