import sys

def solve(a, b):
	if a == b:
		return 0

	ops = []
	while a != 0 and b != 0:
		if a > b:
			ops.append((1, a//b))
			a %= b
		else:
			ops.append((2, b//a))
			b %= a
	ops[-1] = ops[-1][0], ops[-1][1] - 1
	
	res = 0
	for i in range(len(ops) - 1, -1, -1):
		for _ in range(ops[i][1]):
			res = res * 2 + (2 if ops[i][0] == 1 else 1)
	return res


for line in sys.stdin:
	if line.strip() == "":
		break
	p, q = map(int, line.split())
	print(solve(p, q))