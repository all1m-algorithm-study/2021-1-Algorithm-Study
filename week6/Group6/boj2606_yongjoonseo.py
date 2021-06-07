import sys
input = sys.stdin.readline

def DFS(graph, visited, start, V):
    stack = [start]
    cnt = 0

    while stack:
        node = stack.pop()
        for i in range(1, V+1):
            if graph[node][i] and not visited[i]:
                stack.append(i)
                visited[i] = 1
                cnt += 1
    return cnt

def solution(V, E):
    graph = [[0] * (V+1) for _ in range(V+1)]
    visited = [0] * (V+1)
    for _ in range(E):
        s, e = map(int, input().split())
        graph[s][e] = 1
        graph[e][s] = 1
    
    visited[1] = 1
    print(DFS(graph, visited, 1, V))

if __name__ == '__main__':
    solution(int(input()), int(input()))



import sys
input = sys.stdin.readline

def DFS(graph, visited, node, V):
    cnt = 0
    for i in range(1, V+1):
        if graph[node][i] and not visited[i]:
            visited[i] = 1
            cnt += 1
            cnt += DFS(graph, visited, i, V)
    return cnt

def solution(V, E):
    graph = [[0] * (V+1) for _ in range(V+1)]
    visited = [0] * (V+1)
    for _ in range(E):
        s, e = map(int, input().split())
        graph[s][e] = 1
        graph[e][s] = 1
    visited[1] = 1
    print(DFS(graph, visited, 1, V))

if __name__ == '__main__':
    solution(int(input()), int(input()))



import sys
input = sys.stdin.readline
from collections import deque

def BFS(graph, visited, start, V):
    q = deque([start])
    cnt = 0
    while q:
        node = q.popleft()
        for i in range(1, V+1):
            if graph[node][i] and not visited[i]:
                visited[i] = 1
                q.append(i)
                cnt += 1
    return cnt

def solution(V, E):
    graph = [[0] * (V+1) for _ in range(V+1)]
    visited = [0] * (V+1)
    for _ in range(E):
        s, e = map(int, input().split())
        graph[s][e] = 1
        graph[e][s] = 1
    visited[1] = 1
    print(BFS(graph, visited, 1, V))

if __name__ == '__main__':
    solution(int(input()), int(input()))



import sys
input = sys.stdin.readline

def find(x, parents):
    if parents[x] == x: return x
    parents[x] = find(parents[x], parents)
    return parents[x]

def union(x, y, parents, ranks, cnts):
    xr = find(x, parents)
    yr = find(y, parents)
    if ranks[xr] >= ranks[yr]: 
        parents[yr] = xr
        cnts[xr] += cnts[yr]
    else: 
        parents[xr] = yr
        cnts[yr] += cnts[xr]
    if ranks[xr] == ranks[yr]: ranks[xr] += 1

def solution(V, E):
    parents = [i for i in range(V+1)]
    ranks = [0] * (V+1)
    cnts = [1] * (V+1)
    for _ in range(E):
        s, e = map(int, input().split())
        if find(s, parents) != find(e, parents):
            union(s, e, parents, ranks, cnts)
    print(cnts[find(1, parents)] - 1)

if __name__ == '__main__':
    solution(int(input()), int(input()))
