n, l = map(int, input().split())
leakLst = list(map(int, input().split()))
leakLst.sort()
tapeNum = 1
length = leakLst[0] + (l - 1)
for i in range(1, n):
    if leakLst[i] <= length:
        continue
    tapeNum += 1
    length = leakLst[i] + (l - 1)
print(tapeNum)
