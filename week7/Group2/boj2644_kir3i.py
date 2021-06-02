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

if __name__ == '__main__':
    N = int(input().strip())
    start, target = map(int, input().strip().split())
    M = int(input().strip())
    adj = init(N, M)

    print(bfs(adj, start, target))
