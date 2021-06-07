n = int(input())
edges = [[] for _ in range(n+1)]
parent = [-1 for _ in range(n+1)]

def dfs():
    global edges, parent
    parent[1] = 1
    stack = [1]
    
    while stack:
        curr = stack.pop()
        # print(curr)
        for node in edges[curr]:
            if parent[node] == -1:
                parent[node] = curr
                stack.append(node)
                edges[node].remove(curr)

for _ in range(n - 1):
    a, b = map(int, input().split(' '))
    edges[a].append(b)
    edges[b].append(a)

dfs()
# print(edges)
for i in range(2, n+1):
    print(parent[i])