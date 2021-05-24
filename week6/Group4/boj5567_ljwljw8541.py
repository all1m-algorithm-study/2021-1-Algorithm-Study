#boj5567_ljwljw8541

#자신의 친구와 친구의 친구까지만 초대
from sys import stdin
input = stdin.readline

N = int(input())
M = int(input())
#그래프 생성
graph = [[] for _ in range(N+1)]

for _ in range(M):
    x,y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)

def invite(start,invited):
    
    if start != 1 and not start in graph[1]:
        return

    for next in graph[start]:
        if not next in invited:
            invited.append(next)
            invite(next,invited)
    
    return len(invited)-1

print(invite(1,[]))