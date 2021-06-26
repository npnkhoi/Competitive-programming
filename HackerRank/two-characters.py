n = int(input())

s = input()

res = 0

for x in range(26):
	for y in range(x + 1, 26):
		pre = -1
		cnt = 0
		for i in range(n):
			tmp = ord(s[i]) - ord('a')
			if (tmp == x) or (tmp == y):
				if tmp == pre:
					cnt = 0
					break
				else:
					pre = tmp
					cnt += 1
		if (cnt >= 2):
			res = max(res, cnt)


print(res)
