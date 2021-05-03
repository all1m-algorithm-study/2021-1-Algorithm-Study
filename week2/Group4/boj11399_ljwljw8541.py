N = int(input())
K = list(map(int,input().split()))
K.sort()
Min_sum = 0
for i in range(N):
    Min_sum += (N-i)*K[i]
print(Min_sum)