import sys
from collections import deque
input = sys.stdin.readline

def init():
    N = int(input().strip())
    e = int(input().strip())
    adj = [[] for _ in range(N+1)]
    for _ in range(e):
        x, y = map(int, input().strip().split())
        adj[x].append(y)
        adj[y].append(x)
    return N, adj

def bfs(adj, start):
    vst = set([start])
    q = deque([start])
    cnt = 0
    while q:
        curr = q.popleft()
        if curr != start:
            cnt += 1
        for nxt in adj[curr]:
            if nxt not in vst:
                q.append(nxt)
                vst.add(nxt)
    return cnt


if __name__ == '__main__':
    start = 1
    N, adj = init()
    print(bfs(adj, start))
