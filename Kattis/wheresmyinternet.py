n, m = map(int, input().split())

adj = []
for i in range(n):
  adj.append([])

vis = [False for _ in range(n)]

for _ in range(m):
  a, b = map(int, input().split())
  a -= 1
  b -= 1
  adj[a].append(b)
  adj[b].append(a)

# print(adj)

def dfs(v: int) -> None:
  vis[v] = True
  for x in adj[v]:
    if not vis[x]:
      dfs(x)

dfs(0)

answer = []
for i in range(n):
  if not vis[i]:
    answer.append(str(i + 1))

if len(answer) == 0:
  print('Connected')
else:
  print('\n'.join(answer))
