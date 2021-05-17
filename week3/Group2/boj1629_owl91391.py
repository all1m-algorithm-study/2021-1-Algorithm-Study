def multi (a,b,c) :
    if (b%2)==1 :
        return (((multi(a,b//2,c)**2)) * a) % c
    elif b == 0 :
        return 1 % c
    else :
        return (multi(a,b//2,c) **2) % c

a,b,c = map(int,input().split())
d=multi(a,b,c)
print(d)