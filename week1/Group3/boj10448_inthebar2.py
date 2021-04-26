N = int(input())
K = list()
T = list()
res = list()

for i in range(0, N):
    K.append(int(input()))

for i in range(1, 45): # T44 = 990
    T.append((i*i+i)/2)

for i in range(0, len(T)):
    for j in range(0, len(T)):
        for k in range(0, len(T)):
            res.append(T[i]+T[j]+T[k])

for k in K:
    if k in res:
        print(1)
    else:
        print(0)
