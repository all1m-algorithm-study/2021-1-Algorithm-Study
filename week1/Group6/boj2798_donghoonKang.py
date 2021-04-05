N, M = map(int, input().split())
cards = list(map(int, input().split()))

first, second, third = 0, 0, 0
maxNum = 0

for i in cards:
    copyCards1 = cards[:]
    copyCards1.remove(i)
    for j in copyCards1:
        copyCards2 = copyCards1[:]
        copyCards2.remove(j)
        for k in copyCards2:
            thisSum = i+j+k
            if (thisSum <= M) and (thisSum > maxNum):
                maxNum = thisSum
                first, second, third = i, j, k

result = first+second+third
print(result)
