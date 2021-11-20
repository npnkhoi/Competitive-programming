import random


with open('foo.txt', 'w+') as f:
  for _ in range(10**6):
    print(chr(ord('a') + random.randint(0, 25)), end='', file=f)