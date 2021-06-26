tc = int(input())

def add(pos, val):
	cnt_val[pos] += 1
	cnt_pos[val] += 1

def fill(pos, val):
	if a[pos] != -1:
		no_sol = True
		return
	a[pos] = val
	cnt_pos[val] --;
	cnt_pos[val] = 0;
	if cnt_pos[val] == 1:
		new_pos = val * 2 - pos
		fill(new_pos, new_pos * 2 - val)

no_sol = False

for _ in range(tc):
	n, k = map(int, input().split())
	no_sol = False
	a = [-1 for i in range(n)]
	for i in range(n):
		if i - k >= 0:
			add(i, i - k)
		if i + k < n:
			add(i, i + k)

	for i in range(n):
		if no_sol:
			break
		if cnt_val[i] == 1:
			fill(i, (i + k if i + k < n else i - k))

	if no_sol:
		print(-1)
	else:
		print(a.join(" "))
