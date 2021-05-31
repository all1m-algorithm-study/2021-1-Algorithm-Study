#boj9466_ljwljw8541
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)
#한번 순환하면 다시 순환시키면서 
#해당하는 숫자를 체크

#visited가 0이면 방문안한거
#visited가 1이면 방문한거
#visited가 2면 순환한거(팀에 가입된거)

def team(start):
    if visited[start] == 2:
        return
    visited[start] = 2
    next = graph[start]
    
    team(next)
        
def dfs(start):
    if graph[start] == start:
        visited[start] = 2
        return

    visited[start] = 1
    next = graph[start]
    
    if visited[next] == 1: 
        team(next)
    elif visited[next] == 0:
        dfs(next)

    if visited[start] == 1:
        a.add(start)


T = int(input())

for _ in range(T):
    N = int(input().rstrip())
    count = 0
    a = set()
    graph = [0]+ list(map(int, input().split()))

    visited = [0]*(N+1)
    
    for i in range(1,N+1):
        if visited[i] == 0:
            dfs(i)
        
    print(len(a))