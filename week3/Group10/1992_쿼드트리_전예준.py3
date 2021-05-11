N=int(input())
L=[]
for i in range(N):
    L+=[[i for i in input()]]
def f(X,Y,s):
    n=L[X][Y]
    for x in range(X,X+s):
        for y in range(Y,Y+s):
            if n!=L[x][y]:
                s//=2
                return '('+f(X,Y,s)+f(X,Y+s,s)+f(X+s,Y,s)+f(X+s,Y+s,s)+')'
    return n
print(f(0,0,N))