import sys
input = sys.stdin.readline
from collections import deque

def bfs(adj, start, target):
    vst = set([start])
    q = deque([(start, 0)])
    while q:
        curr, dist = q.popleft()
        if curr == target:
            return dist
        for nxt in adj[curr]:
            if nxt not in vst:
                vst.add(nxt)
                q.append((nxt, dist+1))
    return -1
        
n = int(input())
a, b = map(int, input().split())
m = int(input())
graph = [[] for _ in range(n+1)]
cnt = 0
for i in range(m) :
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)
print(bfs(graph,a,b))