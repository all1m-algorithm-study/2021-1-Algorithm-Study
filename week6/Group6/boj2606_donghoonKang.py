nodeNum = int(input())
edgeNum = int(input())
computers = [[0 for i in range(nodeNum)] for j in range(nodeNum)]
for k in range(edgeNum):
    x, y = map(int, input().split())
    computers[x-1][y-1] = 1
    computers[y-1][x-1] = 1

graph = {}
for i in range(nodeNum):
    tmpList = []
    for j in range(nodeNum):
        if computers[i][j] == 1:
            tmpList.append(str(j+1))
    graph[str(i+1)] = tmpList


def bfs(graph, startNode):
    visit = []
    queue = []
    queue.append(startNode)
    while queue:
        node = queue.pop(0)
        if node not in visit:
            visit.append(node)
            queue.extend(graph[node])
    return visit


answerList = bfs(graph, '1')
print(len(answerList)-1)
