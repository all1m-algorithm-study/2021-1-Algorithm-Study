n=int(input())
k=0
for i in range(n):
    k=2*k+1
print(k)
def f(N,x,y):
    if N>1:
        f(N-1,x,6-x-y)
    print(x,y)
    if N>1:
        f(N-1,6-x-y,y)
f(n,1,3)