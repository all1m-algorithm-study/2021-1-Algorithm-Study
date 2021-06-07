import sys
input = sys.stdin.readline

n = int(input())
m = int(input())

link = [[] for _ in range(n + 1)]
visited = []


for _ in range(m):
    a, b = map(int, input().split())
    link[a].append(b)
    link[b].append(a)

for i in link[1]:
    if not i in visited:
        visited.append(i)
    for j in link[i]:
        if not j in visited:
            visited.append(j)

print(len(visited)-1)
