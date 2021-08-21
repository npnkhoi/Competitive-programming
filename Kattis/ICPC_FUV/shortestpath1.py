# This is Python code :D

while True: # Do this for multiple testcases

  # Read input
  
  n, m, q, s = map(int, input().split()) 
  # ^ trick to read multiple numbers on the same line
  
  if n == 0:
    break
  
  adj = [[] for _ in range(n)] # <- adjacency list

  # Read the edges
  for _ in range(m):
    u, v, w = map(int, input().split())
    adj[u].append((v, w))
  
  INF = 10**9 # This is infinity number
  dist = [INF for _ in range(n)] # This list stores shortest distance
  vis = [False for _ in range(n)] # This list shows whether a node is visited
  
  dist[s] = 0 # Initially, distance of s is 0, right?

  for _ in range(n):
    # Find the node with minimum dist (pivot)
    pivot = -1
    for i in range(n):
      if not vis[i] and (pivot == -1 or dist[i] < dist[pivot]):
        pivot = i
    vis[pivot] = True # Now, we have visited the pivot

    # Update other nodes from the pivot
    for v, w in adj[pivot]:
      dist[v] = min(dist[v], dist[pivot] + w)
  
  # Answer the queries!
  for _ in range(q):
    v = int(input())
    print(dist[v] if dist[v] != INF else "Impossible")
  
  print()