import sys
sys.setrecursionlimit(2500)

n, m = map(int, input().split())

edges = [[] for _ in range(n+1)]
group = [0 for _ in range(n+1)]

def dfs(node, groupNumber):
    group[node] = groupNumber

    for edge in edges[node]:
        if group[edge] == 0:
            dfs(edge, groupNumber)

for _ in range(m):
    a, b = map(int, input().split())
    edges[a].append(b)
    edges[b].append(a)

cnt = 0
for i in range(1, n+1):
    if group[i] == 0:
        cnt += 1
        dfs(i, cnt)

print(cnt)