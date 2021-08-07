"""https://open.kattis.com/problems/lostmap"""

"""Section 1: Read input"""
n = int(input())
edge = []
for i in range(n):
    edge.append(list(map(int, input().split())))

"""Section 2: Prim Algorithm"""

# Init
in_mst = [False] * n
dist_to_mst = [None] * n
INF = 3 * 10**9

# Add node 0 -> update
in_mst[0] = True
for i in range(1, n):
    dist_to_mst[i] = (edge[0][i], 0)

# Run Prim
for _ in range(n-1):
    min_dist = INF
    
    # Find the node nearest to the current MST
    for i in range(n):
        if (not in_mst[i]) and (dist_to_mst[i][0] < min_dist):
            min_dist = dist_to_mst[i][0]
            min_edge = (dist_to_mst[i][1], i)
    
    new_node = min_edge[1]
    in_mst[new_node] = True
    
    # Update dist_to_mst[]
    for i in range(n):
        if (not in_mst[i]) and edge[new_node][i] < dist_to_mst[i][0]:
            dist_to_mst[i] = (edge[new_node][i], new_node)

    # Print this edge immediately
    print(min_edge[0] + 1, min_edge[1] + 1)