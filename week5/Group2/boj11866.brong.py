from collections import deque

N, K = map(int,input().split())

queue = deque([])

for i in range(N):
    queue.append(i+1)

answer = []

while len(answer) != N:
    x = 0
    while x < K :
        if x == K-1:
            answer.append(queue.popleft())
            x += 1
        else:
            queue.append(queue.popleft())
            x += 1

print("<" , ', '.join((str(i) for i in answer)) , ">" , sep="")






