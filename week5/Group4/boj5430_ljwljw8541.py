#boj5430_ljwljw8541
from sys import stdin
input = stdin.readline
from collections import deque

T = int(input())
    
def sol(func,dq):
    state = 0 #0은 똑바로, 1은 거꾸로
    try:
        for c in func:
            if c == 'R':
                if state == 0:
                    state = 1
                elif state == 1:
                    state = 0
            
            elif c == 'D':
                if state == 0:
                    dq.popleft()
                elif state == 1:
                    dq.pop()
        if state == 0:
            print('[' + ','.join(map(str, list(dq))) + ']')
        elif state == 1:
            dq.reverse()
            print('[' + ','.join(map(str, list(dq))) + ']')
    except:
        print('error')
    
for _ in range(T):
    func = str(input())
    N = int(input())
    K = list(input().strip().lstrip('[').rstrip(']').split(','))
    dq = deque([])
    
    for c in K:
        if c != '[' and c !=']' and c != ',' and c != '':
            dq.append(int(c))
    sol(func,dq)
    