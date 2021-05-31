import sys
input = sys.stdin.readline
sys.setrecursionlimit(100500)

def init(N):
    adj = [[] for _ in range(N+1)]
    for _ in range(N-1):
        x, y = map(int, input().strip().split())
        adj[x].append(y)
        adj[y].append(x)
    return adj

def dfs(adj, curr, parent, vst):
    vst.add(curr)
    for nxt in adj[curr]:
        if nxt not in vst:
            parent[nxt] = curr
            dfs(adj, nxt, parent, vst)

if __name__ == '__main__':
    N = int(input().strip())
    adj = init(N)
    ans = [0] * (N+1)
    dfs(adj, 1, ans, set())
    print('\n'.join(map(str, ans[2:])))
