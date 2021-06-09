#boj1697_ljwljw8541
from sys import stdin
from collections import deque
input = stdin.readline
N,K = map(int, input().split())
visited = [False]*(10**5+1)
time = 0
def bfs(start,end):
    global time
    
    q = deque([start])
    visited[start] = True
    
    while q:
        
        for _ in range(len(q)):
            now = q.popleft()
            
            move = [now+1,now-1,now*2]
            for next in move:
                if 0<=next<=10**5:
                    if next == end:
                        return time + 1
                    if not visited[next]:
                        q.append(next)
                        visited[next] = True
        time += 1

if N>K:
    print(N-K)
elif N == K:
    print(0)
else:
    print(bfs(N,K))