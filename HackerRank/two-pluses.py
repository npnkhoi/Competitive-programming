n, m = map(int, input().split())
a = []
for i in range(n):
	a.append(list(map(int, input().split())))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for x in range(n):
	for y in range(m):
		if a[x][y] == 'B':
			radius[x][y] = -1
			continue
		r = 0
		ok = True
		while ok:
			for drt in range(4):
				u = x + dx[drt] * r
				v = y + dy[drt] * r
				if not (in_board(u, v) and a[u][v] == 'G'):
					ok = False
					break
			if ok:
				r += 1
		radius[x][y] = r


