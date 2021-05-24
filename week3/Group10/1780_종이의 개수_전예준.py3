D={2:0,1:0,0:0,-1:0}
def F(L):
    n=len(L)
    k=n//3
    L1=[list() for _ in range(k*k)]
    for i in range(n):
        for j in range(n):
            L1[i//3*k+j//3]+=[L[i][j]]
    for j in range(k*k):
        p=L1[j][0]
        for u in L1[j]:
            if u!=p:
                for r in L1[j]:
                    D[r]+=1
                L1[j]=2
                break
        else:
            L1[j]=p
    L1=[L1[i:i+k] for i in range(0,k*k,k)]
    return L1
n=int(input())
L=[]
for i in range(n):
    L+=[list(map(int,input().split()))]
while len(L)>1:
    L=F(L)
D[L[0][0]]+=1
print(D[-1])
print(D[0])
print(D[1])