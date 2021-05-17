from collections import deque
for _ in range(int(input())):
    counter=0
    n,m=map(int,input().split())
    Q=deque(list(map(int,input().split())))
    while len(Q)>0:
        if m==0 and Q[0]==max(Q):
            counter+=1
            print(counter)
            break
        elif m==0:
            m=len(Q)-1
            Q.append(Q.popleft())
        elif Q[0]==max(Q):
            counter+=1
            m-=1
            Q.popleft()
        else:
            Q.append(Q.popleft())
            m-=1