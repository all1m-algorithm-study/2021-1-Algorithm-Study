N = int(input())
x = []
y = []
for i in range(N):
    a, b = input().split(' ')
    x.append(int(a))
    y.append(int(b))

sum = 0
for i in range(N-2):
    for j in range(i+1, N-1):
        for k in range(j+1, N):
            sum = max(sum, (abs(((x[i]*y[j])+(x[j]*y[k])+(x[k]*y[i]))-((x[j]*y[i])+(x[k]*y[j])+(x[i]*y[k]))))/2)

print(sum)