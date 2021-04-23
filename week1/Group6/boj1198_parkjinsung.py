n = int(input())
pointLst = []
S = 0
for p in range(n):
    pointLst.append(list(map(int, input().split())))

for i in range(n):
    for j in range(i, n):
        for k in range(j, n):
            a = pointLst[i][0]
            b = pointLst[i][1]
            c = pointLst[j][0]
            d = pointLst[j][1]
            e = pointLst[k][0]
            f = pointLst[k][1]
            tempS = ((a*d + c*f + e*b) - (c*b + e*d + a*f))/2
            if tempS < 0:
                tempS = -tempS
            if S < tempS:
                S = tempS
print(S)
