#boj2251_ljwljw8541
import sys
input = sys.stdin.readline
from collections import deque
MaxA,MaxB,MaxC = map(int, input().split())
#Max는 최대량, V는 현재량
Max = [MaxA,MaxB,MaxC]
V = [0,0,MaxC]

q = deque([V])
visited = set()
visited.add(tuple(V))
k_start = [0,0,1,1,2,2]
k_end   = [1,2,0,2,0,1]

def pour(st,ed,V):
    if V[st] == 0:
        return
    max_pour = Max[ed] - V[ed]
    if V[st] >= max_pour:
        V[st] -= max_pour
        V[ed] += max_pour
    else:
        V[ed] += V[st]
        V[st] = 0
        
while q:
    a,b,c = q.popleft()
    
    for i in range(6):
        now= [a,b,c]
        start = k_start[i]
        end = k_end[i]
        pour(start,end,now)
        if not tuple(now) in visited:
            visited.add(tuple(now))
            q.append(tuple(now))
answer = []
for c in visited:
    if c[0] == 0 and not c[2] in answer:
        answer.append(c[2])
answer.sort()
print(*answer)