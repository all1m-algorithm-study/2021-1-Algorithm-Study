import sys
from collections import deque
input = sys.stdin.readline

def init(N, M):
    adj = [[] for _ in range(N+1)]
    for _ in range(M):
        x, y = map(int, input().strip().split())
        adj[x].append(y)
        adj[y].append(x)
    return adj

def bfs(adj, start):
    vst = set([start])
    q = deque([(start, 0)])
    cnt = 0
    while q:
        curr, dist = q.popleft()
        if curr != start:
            cnt += 1
        for nxt in adj[curr]:
            if dist < 2 and nxt not in vst:
                q.append((nxt, dist+1))
                vst.add(nxt)
    return cnt

if __name__ == '__main__':
    N = int(input().strip())
    M = int(input().strip())
    adj = init(N, M)

    print(bfs(adj, 1))
