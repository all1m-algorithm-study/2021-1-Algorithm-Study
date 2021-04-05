N = int(input())
X = []
Y = []

for i in range(N):
    x, y = map(int, input().split())
    X.append(x); Y.append(y)

MaxArea = 0
for i in range(N-1):
    for j in range(i+1, N):
        for k in range(j+1, N):
            Area = 0.5*abs(X[i]*Y[j]+X[j]*Y[k]+X[k]*Y[i]-X[j]*Y[i]-X[k]*Y[j]-X[i]*Y[k])
            if Area > MaxArea:
                MaxArea = Area

print(MaxArea)