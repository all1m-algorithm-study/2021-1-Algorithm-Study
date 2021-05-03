def comb (n,m,st,se) :
    if len(se) == m:
        print(*se)
    elif st <=n :
        se.append(st)
        comb(n,m,st+1,se)
        se.pop()
        comb(n,m,st+1,se)

n ,m = map(int,input().split())
comb(n,m,1,[])
