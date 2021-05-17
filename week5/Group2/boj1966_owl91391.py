import sys
input = sys.stdin.readline
from collections import deque


case = int(input())
for _ in range(case) :
    N, M = map(int,input().split())
    imp_figure = list(map(int,input().split()))
    file = deque(imp_figure)
    answer=0
    while M >= 0 :
        if file[0] >= max(file) :
            file.popleft()
            M -=1
            answer +=1
        else :
            if M == 0:
                M = len(file) -1
            else :
                M -=1
            a = file.popleft()
            file.append(a)
    print(answer)