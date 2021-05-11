def comb (n,m,st,se) :
    if len(se) == m:
        print(*se)
    elif st <=(len(s)-1) :
        se.append(s[st])
        comb(n,m,st+1,se)
        se.pop()
        comb(n,m,st+1,se)

while True :
    s = list(map(int,input().split()))
    if s == [0] :
        break
    else :
        del s[0]
    comb(s,6,0,[])
    print('')