from collections import deque
from sys import stdin
input = stdin.readline

dq = deque([])

Q = int(input())
for _ in range(Q):
    query = input().split()

    if query[0] == "push_front":
        dq.appendleft(query[1])

    if query[0] == "push_back":
        dq.append(query[1])
    
    if query[0] == "pop_front":
        if len(dq) == 0:
            print(-1)
        else:    
            print(dq.popleft())
        
    if query[0] == "pop_back":
        if len(dq) == 0:
            print(-1)
        else:
            print(dq.pop())
    
    if query[0] == "size":
        print(len(dq))

    if query[0] == "empty":
        if len(dq) == 0:
            print(1)
        else:
            print(0)

    if query[0] == "front":
        if len(dq) == 0:
            print(-1)
        else:
            print(dq[0])
    
    if query[0] == "back":
        if len(dq) == 0:
            print(-1)
        else:
            print(dq[-1])
