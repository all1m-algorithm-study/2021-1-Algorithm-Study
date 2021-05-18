import sys
sys.setrecursionlimit(10000)

nodeNum, edgeNum = map(int, sys.stdin.readline().split())
adj = [[] for _ in range(nodeNum+1)]
visit = [False] * (nodeNum+1)
for _ in range(edgeNum):
    x, y = map(int, sys.stdin.readline().split())
    adj[x].append(y)
    adj[y].append(x)


def dfs(startNode):
    global visit
    visit[startNode] = True
    for i in adj[startNode]:
        if not visit[i]:
            dfs(i)


count = 0
for i in range(1, nodeNum+1):
    if not visit[i]:
        dfs(i)
        count += 1

print(count)
