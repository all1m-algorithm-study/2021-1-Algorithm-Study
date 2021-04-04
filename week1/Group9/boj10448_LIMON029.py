def solve(K,T):
    solved=False
    for i in range(50):
        for j in range(50):
            for k in range(50):
                result = T[i] + T[j] + T[k]
                if result == K:
                    solved=True
                    print(1)
                    break
            if solved:
                break
        if solved:
            break
    if solved==False:
        print(0)


T=[]
for i in range(1,51):
    T.append(i*(i+1)//2)

N = int(input())
num = []
for i in range(N):
    num.append(int(input()))
for i in range(N):
    solve(num[i],T)