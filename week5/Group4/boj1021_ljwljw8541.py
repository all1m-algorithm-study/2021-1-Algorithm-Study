#boj1021_ljwljw8541

#첫 번째 원소를 뽑아낸다.
#->popleft
# ****popleft 밖에 못함. pop  (x)
#왼쪽으로 한 칸 이동시킨다.
#->rotate(-1)
# 0 1 2 3 -> 1 2 3 0
#오른쪽으로 한 칸 이동시킨다.
#->rotate(1)
# 0 1 2 3 -> 3 0 1 2

from sys import stdin
input = stdin.readline

from collections import deque

N,M = map(int,input().split())
pullout = map(int,input().split())

queue = deque(list(range(1,N+1)))

count = 0
#왼쪽이 빠르냐 오른쪽이 빠르냐?
#왼쪽으로 가는건 뽑아내려는 수의 인덱스 값과 같다.
#오른쪽으로 가는건?
for i in pullout:
    if queue.index(i) >= len(queue)-queue.index(i):
        R = len(queue)-queue.index(i)
        queue.rotate(R)
        queue.popleft()
        count += R
    else:
        R = queue.index(i)
        queue.rotate(-R)
        queue.popleft()
        count += R
    
print(count)
