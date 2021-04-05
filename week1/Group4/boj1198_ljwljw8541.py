N = int(input())
T=[]
W = []
for i in range(N):
    x = list(map(int, input().split()))
    T.append(x)
for i in range(N):
    for j in range(N):
        for k in range(N):
            if (i-j)*(j-k)*(k-i) == 0:
                continue
            a = T[i][0]
            b = T[i][1]
            c = T[j][0]
            d = T[j][1]
            e = T[k][0]
            f = T[k][1]
            S = (1/2)*abs((a*d+c*f+e*b)-(c*b+e*d+a*f))
            W.append(S)
print(max(W))
