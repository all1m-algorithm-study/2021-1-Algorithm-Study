from collections import deque

n = int(input())
line = deque(map(int, input().split()))
extraline = deque()

a=1
while line:
    if line and line[0] == a :
        line.popleft()
        a +=1
    else :
        extraline.appendleft(line.popleft())
    while extraline and extraline[0] == a :
        extraline.popleft()
        a += 1

if len(extraline) == 0 :
    print("Nice")
else :
    print("Sad")