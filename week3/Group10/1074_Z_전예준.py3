def f(n,r,c):
    if n==1:
        if (r,c)==(0,0):
            return 0
        elif (r,c)==(0,1):
            return 1
        elif (r,c)==(1,0):
            return 2
        else:
            return 3
    k=2**(n-1)
    if r<k:
        if c<k:
            return f(n-1,r,c)
        else:
            return f(n-1,r,c-k)+k*k
    else:
        if c<k:
            return f(n-1,r-k,c)+2*k*k
        else:
            return f(n-1,r-k,c-k)+3*k*k
n,r,c=map(int,input().split())
print(f(n,r,c))