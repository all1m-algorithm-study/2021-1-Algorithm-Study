L=['  *   ',' * *  ','***** ']
def f(N):
    for i in range(len(L)):
        L.append(L[i]+L[i])
        L[i]=' '*N+L[i]+' '*N
n=int(input())
n/=3
while n>1:
    f(len(L))
    n/=2
for i in L:
    print(i)