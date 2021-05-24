#boj12789_ljwljw8541

from sys import stdin
input = stdin.readline
from collections import deque

N = int(input())
dq = deque([])
K = list(map(int, input().split()))
for c in K:
    dq.append(c)
stack = []


i = 1
while i <= N+1:
    if len(dq) == 0:
        if len(stack) == 0:
            print('Nice')
            break
        else:
            if stack[-1] != i:
                print('Sad')
                break
            else:
                stack.pop()
                i += 1
    else:
        if len(stack) == 0:
            stack.append(dq[0])
            dq.popleft()
        else:
            if stack[-1] == i:
                stack.pop()
                i += 1
            elif dq[0] == i:
                dq.popleft()
                i +=1
            else:
                stack.append(dq[0])
                dq.popleft()