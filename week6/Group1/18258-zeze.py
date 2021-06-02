import sys
from collections import deque

input = sys.stdin.readline

num = int(input())
que = deque([])

for _ in range(num):
    command = list(input().split())

    if command[0] == 'push':
        que.append(command[1])
    elif command[0] == 'pop':
        if len(que) == 0:
            print(-1)
        else:
            print(que.popleft())
            
    elif command[0] == 'size':
        print(len(que))
    elif command[0] == 'empty':
        if len(que) == 0:
            print(1)
        else:
            print(0)
    elif command[0] == 'front':
        if len(que) == 0:
            print(-1)
        else:
            print(que[0])
    else:
        if len(que) == 0:
            print(-1)
        else:
            print(que[-1])
