N=int(input())
x=0
for i in range (1,N+1):
    s=sum(map(int, str(i)))
    x = i + s
    if x == N:
        print(i)
        break
    elif i == N:
        print(0)
