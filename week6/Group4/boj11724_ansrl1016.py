import sys
input = sys.stdin.readline

n, m = map(int, input().split())
link = [[] for _ in range(n + 1)]
visited = [False] * (n +1)

for _ in range(m):
    a, b = map(int, input().split())
    link[a].append(b)
    link[b].append(a)

def explore(start) :
    visited[start] = True
    for i in link[start]:
        if not visited[i]:
            explore(i)

cnt = 0

for j in range(1, n + 1):
    if not visited[j]:
        explore(j)
        cnt += 1

print(cnt)