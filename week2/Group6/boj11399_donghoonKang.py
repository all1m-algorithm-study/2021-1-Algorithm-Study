N = int(input())
P = list(map(int, input().split()))
P.sort()

sum, sumOfSum = 0, 0

for i in range(N):
    sumOfSum += P[i]
    sum += sumOfSum

print(sum)
