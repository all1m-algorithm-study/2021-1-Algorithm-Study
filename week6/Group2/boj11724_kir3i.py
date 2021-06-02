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

def bfs(adj, vst, start):
    q = deque([start])
    vst[start] = True

    while q:
        curr = q.popleft()
        for nxt in adj[curr]:
            if not vst[nxt]:
                q.append(nxt)
                vst[nxt] = True

if __name__ == '__main__':
    N, M = map(int, input().strip().split())
    adj = init(N, M)
    vst = [False] * (N+1)

    cnt = 0
    for n in range(1, N+1):
        if not vst[n]:
            bfs(adj, vst, n)
            cnt += 1
    print(cnt)
