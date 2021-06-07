import sys
input = sys.stdin.readline

n = int(input())
m = int(input())

link = [[] for _ in range(n + 1)]


for i in range(m):
    a, b = map(int, input().split())
    link[a].append(b)
    link[b].append(a)


def explore (start):
    for i in link[start]:
        if not i in visited:
            visited.append(i)
            explore (i)

visited = []
explore (1)
print(len(visited)-1)

