import sys
input = sys.stdin.readline

def dfs(graph,start, parent) :
    stack = [start]
    while stack :
        n = stack.pop()
        for i in graph[n] :
            parent[i].append(n)
            stack.append(i)
            graph[i].remove(n)
    return parent

N = int(input())
graph= [[] for _ in range(N+1)]
for k in range(N-1) :
    x,y = map(int,input().split())
    graph[x].append(y)
    graph[y].append(x)
parent = [[] for _ in range(N+1)]

for i in list(dfs(graph, 1, parent))[2:] :
    print(i[0])