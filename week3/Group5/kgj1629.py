def multiple(val,exp,mod):
    if exp==0:
        return 1
    elif exp%2==0:
        return (multiple(val,exp//2,mod)**2)%mod
    else:
        return ((multiple(val,exp//2,mod)**2)*val)%mod

a,b,c=map(int,input().split())
print(multiple(a,b,c))
