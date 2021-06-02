n = int(input())
k = int(input())

edges = [[] for _ in range(n+1)]
visited = [False for _ in range(n+1)]

def dfs(curr):
    visited[curr] = True

    for edge in edges[curr]:
        if not visited[edge]:
            dfs(edge)

for _ in range(k):
    a, b = map(int, input().split())
    edges[a].append(b)
    edges[b].append(a)

dfs(1)
cnt = 0
for v in visited[2:]:
    if v == True:
        cnt += 1

print(cnt)