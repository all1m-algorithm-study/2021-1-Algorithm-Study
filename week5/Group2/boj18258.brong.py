from collections import deque
from sys import stdin
input = stdin.readline

queue = deque([])

Q = int(input())
for _ in range(Q):
    query = input().split()

    if query[0] == "push":
        item = int(query[1])
        queue.append(item)
    
    if query[0] == "pop":
        if len(queue) == 0:
            print(-1)
        else:
            print(queue.popleft())
    
    if query[0] == "size":
        print(len(queue))

    if query[0] == "empty":
        if len(queue) == 0 :
            print(1)
        else:
            print(0)

    if query[0] == "front":
        if len(queue) == 0 :
            print(-1)
        else:
            print(queue[0])
    
    if query[0] == "back":
        if len(queue) == 0:
            print(-1)
        else:
            print(queue[-1])