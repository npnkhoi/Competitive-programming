l, r = map(int, input().split())
s = input()

l -= 1

t = s[:l] + s[l:r][::-1] + s[r:]
print(t)
