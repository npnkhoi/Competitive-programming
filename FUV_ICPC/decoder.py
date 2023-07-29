message = 'LFSF dw Ixoeuljkw'
shift = 3
result = ''
for c in message:
  if c == ' ':
    result += c
  else:
    result += chr(ord(c) - shift)
print(result)