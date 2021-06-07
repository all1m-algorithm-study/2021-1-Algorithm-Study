from collections import deque
from sys import stdin
input = stdin.readline

def bfs(graph, a, b, vst):
    M, N = len(graph[0]), len(graph)
    vst.append((a,b))  
    q = deque([(a,b)])
    while q:
        y, x = q.popleft()
        for dy, dx in [(1,0), (-1,0), (0,1), (0,-1)]:
            nxt = ( y + dy, x + dx )
            if 0 <=nxt[0]<N and 0<=nxt[1]<M and \
                graph[nxt[0]][nxt[1]]==1 and nxt not in vst:
                q.append((nxt))
                vst.append(nxt)
    return vst

T = int(input())
answer = []
for i in range(T):
    w, h, k = map(int,input().split())
    graph = [ [0 for _ in range(w)] for _ in range(h)]
    vst = []
    num = 0

    for j in range(k):
        a, b = map(int,input().split())
        graph[b][a] = 1

    for k in range(w):
        for l in range(h):
            if graph[l][k]==1 and (l,k) not in vst:
                bfs(graph, l, k, vst)
                num += 1
    answer.append(num)

for i in range(T):
    print(answer[i])

    
