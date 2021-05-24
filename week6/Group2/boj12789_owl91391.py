import sys
input = sys.stdin.readline
from collections import deque

N = int(input())
line = list(map(int,input().split()))
line=deque(line)
store = []
accept = []
s=0
for i in range(1,N+1) :
    if i in line :
        for j in range(line.index(i)) :
            store.append(line.popleft())
        accept.append(line.popleft())
    else :
        if store.index(i) != len(store)-1 :
            s=1
        else :
            accept.append(store.pop())
if s ==1 :
    print("Sad")
else :
    print("Nice")