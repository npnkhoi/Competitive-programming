# Problem: https://open.kattis.com/problems/reachableroads
# This code has got Accepted 

def dfs(vertex, visited):
    visited[vertex] = True
    
    for neighbor in adj[vertex]:
        if not visited[neighbor]:
            dfs(neighbor, visited)    

num_cases = int(input())

for _ in range(num_cases):
    n = int(input())
    m = int(input())

    # Create "adjacent list" for N vertices
    adj = [[] for _ in range(n)]

    # Read the edges
    for _ in range(m):
        a, b = map(int, input().split())
        adj[a].append(b)
        adj[b].append(a)
    
    # Iterate through the "connected components"
    visited = [False] * n
    count = 0
    for i in range(n):
        if not visited[i]:
            dfs(i, visited)
            count += 1
    
    # Num edges need building = num components - 1
    print(count - 1)