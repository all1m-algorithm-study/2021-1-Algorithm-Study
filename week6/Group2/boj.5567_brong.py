from sys import stdin
input = stdin.readline

N = int(input())
M = int(input())

graph = [[] for i in range(N+1)]

for i in range(M):
    (a,b) = list(map(int,input().split()))
    graph[a].append(b)
    graph[b].append(a)    


friends = []

for friend in graph[1]:
    friends.append(friend)
    for j in range(len(graph[friend])):
        friends.append(graph[friend][j])

answer = len(set(friends)) - 1

print(answer)




