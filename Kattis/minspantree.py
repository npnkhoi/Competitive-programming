"""https://open.kattis.com/problems/minspantree"""

up = []

def find(vertex: int) -> int:
    if up[vertex] < 0:
        return vertex
    
    up[vertex] = find(up[vertex])
    return up[vertex]

def union(a: int, b: int) -> bool:
    a = find(a)
    b = find(b)
    
    if (a == b): # same union already
        return False

    # Make sure set a is "bigger" than set b
    if up[a] > up[b]:
        a, b = b, a
    
    up[a] -= 1
    up[b] = a
    return True

while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break
    
    up = [-1] * n
    edges = []
    for i in range(m):
        node1, node2, weight = map(int, input().split())
        if node1 > node2:
            node1, node2 = node2, node1
        edges.append((weight, node1, node2))
    
    edges.sort()
    
    mst = []
    total = 0
    for edge in edges:
        if union(edge[1], edge[2]):
            mst.append((edge[1], edge[2]))
            total += edge[0]

    # print(f'mst = {mst}')
    if len(mst) == n-1:
        print(total)
        
        mst.sort()
        for edge in mst:
            print(edge[0], edge[1])
    else:
        print('Impossible')