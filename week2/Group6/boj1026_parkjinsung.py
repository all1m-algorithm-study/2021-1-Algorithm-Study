n = int(input())

aLst = list(map(int, input().split()))
bLst = list(map(int, input().split()))

copyBLst = bLst

aLst.sort()
copyBLst.sort(reverse=True)

s = 0
for i in range(n):
    s += aLst[i]*copyBLst[i]
print(s)
