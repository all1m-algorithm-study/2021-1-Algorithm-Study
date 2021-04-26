N=int(input())
sum=0
sum2=100000000000
a=0
for i in range(1,N+1):
    sum=0
    a=i
    for c in str(a):
        sum+=int(c)
    sum+=a
    
    if sum==N:
        print(i)
        break
else:
    print(0)

