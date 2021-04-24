N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

bCopy = B[:]
bOrder = []

for i in range(N):
    bMax = -1
    bMaxIndex = None
    for j in range(N):
        if bCopy[j] >= bMax:
            bMax = bCopy[j]
            bMaxIndex = j
    bOrder.append(bMaxIndex)
    bCopy[bMaxIndex] = -1

A.sort()

sum = 0
for k in range(N):
    bIndex = bOrder[k]
    sum += A[k] * B[bIndex]

print(sum)
