N = int(input())
I =[]
for i in range(N):
    K = int(input())
    I.append(K)
#삼각수 리스트
T = []
R = []
for i in range(44):
    T.append((i+1)*(i+2)//2)
K = len(T)
for i in range(K):
    for j in range(K):
        for k in range(K):
            S = T[i] + T[j] + T[k]
            R.append(S)
for i in range(N):
    if I[i] in R:
        print('1')
    else:
        print('0')
