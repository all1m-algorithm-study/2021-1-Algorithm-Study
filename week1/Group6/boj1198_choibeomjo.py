N = int(input())
x=[0]
y=[0]
ans=0
for i in range(N):
    x[i], y[i] = map(int, input().split)

for i in range(N):
    for j in range(i+1,N+1):
        for k in range(j+1,N+1):
            ab = abs(x[i] * y[j] + x[j] * y[k] + x[k] * y[i] - x[j] * y[i] - x[k] * y[j] - x[i] * y[k])
            ans = max(ans, ab)
        if ans % 2:
            print(str(ans)+".5")
        else:
            print(ans)