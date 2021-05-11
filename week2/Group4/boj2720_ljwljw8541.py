N = int(input())
K = [int(input())for i in range(N)]
def Q(x):
    q = x//25
    d = (x-25*q)//10
    n = (x-25*q-10*d)//5
    p = x-25*q-10*d-5*n
    print(q,d,n,p)
for i in range(N):
    Q(K[i])