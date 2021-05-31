V=int(input())
graph=[[] for i in range(V+1)]

for i in range(V-1):
    (a, b)=list(map(int,input().split()))
    graph[a].append(b)
    graph[b].append(a)



visited=[False for i in range(V+1)]
stack=[1]
parent={}

while len(stack)>0:
    now=stack.pop()
    for dest in graph[now]:
        if not visited[dest]:
            parent[dest]=now
            stack.append(dest)
            visited[dest]=True

for i in range(2,V+1):
    print(parent[i])