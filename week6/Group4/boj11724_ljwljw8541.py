#boj11724_ljwljw8541

from sys import stdin
from sys import setrecursionlimit
setrecursionlimit(10**6)
input = stdin.readline

V,E = map(int, input().split())

graph = [[] for _ in range(V+1)]

for _ in range(E):
    x,y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)
visited = []

def visit(start,visited):
    visited.append(start)

    for next in graph[start]:
        if not next in visited:
            visit(next,visited)

count = 0
for i in range(1,V+1):
    if not i in visited:
        visit(i,visited)
        count += 1

print(count)