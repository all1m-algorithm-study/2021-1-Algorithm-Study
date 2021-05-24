#boj11866_ljwljw8541

#N = 6, K = 3이라면?
#1 2 3 4 5 6 -> 2 3 4 5 6 1 -> 3 4 5 6 1 2 -> 3pop -> 4 5 6 1 2 ... 
#queue?
from sys import stdin
input = stdin.readline
from collections import deque

N,K = map(int,input().split())

def josephus(x,y):#x가 N, y가 K
    
    queue = deque([])
    for i in range(1,x+1):
        queue.append(i)

    seq = []
    while len(queue) != 0:
        queue.rotate(-y+1)
        #for _ in range(y-1):
        #    queue.append(queue.pop())

         #맨앞에껄 pop해서 맨뒤로 추가
        seq.append(queue[0])
        queue.popleft()

    print('<', end='')
    print(seq[0],end='')
    for c in seq[1:]:
        print(',',c, end='')
    print('>')

josephus(N,K)
