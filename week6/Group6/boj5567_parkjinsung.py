import sys
sys.setrecursionlimit(10000)

n = int(input())
connect = int(input())
graph = [[0 for j in range(n+1)] for i in range(n+1)]

for i in range(connect):
    a, b = map(int, input().split())
    graph[a][b] = 1
    graph[b][a] = 1

friend_1st = []
for i in range(1, n+1):
    if graph[1][i] == 1:
        friend_1st.append(i)

friend_2nd = []
for j in friend_1st:
    for k in range(1, n+1):
        if graph[j][k] == 1:
            friend_2nd.append(k)

friend = set(friend_1st + friend_2nd)
print(len(friend)-1)
