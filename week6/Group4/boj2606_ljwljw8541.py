#boj2606_ljwljw8541
from sys import stdin
input = stdin.readline

N =int(input())
K = int(input())

#그래프 생성
graph = [[] for _ in range(N+1)]

for _ in range(K):
    x,y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)


def spread(start,infected):
    
    infected.append(start) #start는 감염되었다.

    for next in graph[start]: #start와 연결된 노드 탐색
        if not next in infected:# 연결된게 감염이 안되었다면
            spread(next,infected)# 퍼뜨린다.
    
    return len(infected)-1 #맨첨에 시작한놈 제외

print(spread(1,[]))
