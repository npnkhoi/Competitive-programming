s = input()

cnt = 1
max_len = [0] * 26
for i in range(len(s)):
	if i > 0 and s[i] == s[i - 1]:
		cnt += 1
	else:
		cnt = 1
	char = ord(s[i]) - ord('a')
	max_len[char] = max(max_len[char], cnt)

n = int(input())
for _ in range(n):
	query = int(input())
	answer = False
	for char in range(26):
		if (query % (char + 1) == 0) and (query // (char + 1) <= max_len[char]):
			answer = True
	print('Yes' if answer else 'No')
