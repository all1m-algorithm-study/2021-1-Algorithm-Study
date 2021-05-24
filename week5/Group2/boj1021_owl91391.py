import sys
input = sys.stdin.readline
from collections import deque

size, num = map(int,input().split())
position = list(map(int,input().split()))
cnt =0
nums = []
for k in range(1,size+1) :
    nums.append(k)
size = deque(nums)
position = deque(position)
while position != deque([]) :
    if position[0]==1:
        size.popleft()
        position.popleft()
        for i in range(len(position)) :
            position[i] -= 1
    else :
        right = 0
        left = 0
        if position[0] <= (len(size)+2)//2  :
            size.rotate(-1)
            cnt +=1
            for i in range(len(position)) :
                position[i] -= 1
                if position[i] <= 0 :
                    position[i] = len(size)
        else :
            size.rotate(1)
            cnt += 1
            for i in range(len(position)) :
                position[i] += 1
                if position[i] > len(size) :
                    position[i] = 1

print(cnt)