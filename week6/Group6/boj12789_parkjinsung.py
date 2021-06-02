from collections import deque
n = int(input())
standby = deque(map(int, input().split()))
stack = []

cnt = 1
while cnt < n or standby != []:
    if cnt in standby:
        for i in range(len(standby)):
            if standby[0] == cnt:
                standby.popleft()
                break
            else:
                stack.append(standby.popleft())
    else:
        if stack != [] :
            if stack[-1] == cnt:
                stack.pop()
            else:
                print("Sad")
                break
        else:
            break
    cnt += 1
    

if standby == deque([]) and stack == []:
    print("Nice")
