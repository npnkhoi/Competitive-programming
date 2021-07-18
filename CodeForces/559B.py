def equivalent(a: str, b: str) -> bool:
  """Anwser if a and b are equivalent"""
  if len(a) != len(b):
    return False
  if a == b:
    return True
  if len(a) % 2 == 1:
    return False
  
  half = len(a) // 2
  case_1 = equivalent(a[:half], b[half:]) and equivalent(a[half:], b[:half])
  case_2 = equivalent(a[:half], b[:half]) and equivalent(a[half:], b[half:])
  return case_1 or case_2


a = input()
b = input()

if equivalent(a, b):
  print('YES')
else:
  print('NO')