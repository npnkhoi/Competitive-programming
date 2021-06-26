h, w = map(int, input().split())

def in_board(r, c):
	# check if cell (r, c) is in the board
	return 0 <= r and r < h and 0 <= c and c < w

a = []
for i in range(h):
	a.append(list(map(int, input().split())))

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

result = 2 * h * w

for i in range(h):
	for j in range(w):
		for drt in range(4):
			u = i + dx[drt]
			v = j + dy[drt]
			neighbor = 0
			if in_board(u, v):
				neighbor = a[u][v]
			result += max(0, a[i][j] - neighbor)

print(result)

