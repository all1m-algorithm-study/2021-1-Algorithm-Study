#boj1966_ljwljw8541

from sys import stdin
input = stdin.readline
from collections import deque

K = int(input())

def sol(wonder,importance):
    prcmt = 0
    wonder_index = wonder
    dq = deque([])
    
    for c in importance:
        dq.append(c)
    
    FO = max(dq)

    while not(wonder_index == 0 and dq[0] == FO):

        if dq[0] != FO:
            dq.rotate(-1)
            if wonder_index == 0:
                wonder_index = len(dq) - 1
            else:
                wonder_index -= 1
        elif dq[0] == FO:
            dq.popleft()
            if len(dq) == 0:
                return cnt
            else:
                FO = max(dq)
                wonder_index -= 1
                prcmt += 1

    return prcmt +1

for _ in range(K):

    cnt,wonder = map(int,input().split())
    importance = list(map(int, input().split()))

    print(sol(wonder,importance))
