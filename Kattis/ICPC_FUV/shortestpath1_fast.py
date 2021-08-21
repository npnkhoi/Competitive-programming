from queue import PriorityQueue

while True:
  n, m, q, s = map(int, input().split())
  if n == 0:
    break
  
  adj = [[] for _ in range(n)]
  for _ in range(m):
    u, v, w = map(int, input().split())
    adj[u].append((v, w))
  
  INF = 10**9
  dist = [INF for _ in range(n)]
  heap = PriorityQueue()
  
  dist[s] = 0
  heap.put((0, s))


  while not heap.empty():
    d, pivot = heap.get()
    # print(f'd = {d}, pivot = {pivot}')
    d = -d
    if d > dist[pivot]:
      continue

    for v, w in adj[pivot]:
      if dist[pivot] + w < dist[v]:
        # print(f'update {pivot} -> {v}')
        dist[v] = dist[pivot] + w
        heap.put((-dist[v], v))
  
  for _ in range(q):
    v = int(input())
    print(dist[v] if dist[v] != INF else "Impossible")
  
  print()