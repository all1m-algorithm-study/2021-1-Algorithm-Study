#boj1707_ljwljw8541
from sys import stdin
input = stdin.readline
from collections import deque

def bfs(start):
    
    visited[start] = 1
    q = deque()
    q.append([start,visited[start]])
    while q:
        now,now_num = q.popleft()

        for next in graph[now]:
            if visited[next] == 0:
                if now_num == 1:
                    visited[next] = 2

                elif now_num == 2:
                    visited[next] = 1
                q.append([next,visited[next]])

            elif visited[next] == 1:
                if now_num == 1:
                    return False
            
            elif visited[next] == 2:
                if now_num == 2:
                    return False
    return True

def isbi(graph,visited):
    for i in range(1,V+1):
        if visited[i] == 0:
            k = bfs(i)
            if not k:
                return 'NO'
    return 'YES'

T = int(input())
for _ in range(T):
    #인풋받기
    V,E = map(int,input().split())
    graph = [[] for _ in range(V+1)]
    for _ in range(E):
        x,y = map(int, input().split())
        graph[x].append(y)
        graph[y].append(x)
    visited = [0]*(V+1)
    
    print(isbi(graph,visited))