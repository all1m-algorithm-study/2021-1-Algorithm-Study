numLst1 = ["1", "2", "3", "4", "5", "6", "7", "8", "9"]
numLst2 = []
for i in numLst1:
    for j in numLst1:
        if i != j:
            for k in numLst1:
                if j != k and i != k:
                    numLst2.append(i+j+k)

def distinSB(a, s, b, t):
    cntS = 0
    cntB = 0
    for i in range(3):
        for j in range(3):
            if a[i] == t[j]:
                if i == j:
                    cntS += 1
                else:
                    cntB += 1
                break
    
    if s == str(cntS) and b == str(cntB):
        return t
    return None

n = int(input())

result = []
flag = True
for i in range(n):
    a, s, b = input().split()
    
    for testNum in numLst2:
        temp = distinSB(a, s, b, testNum)
        if temp != None:
            result.append(temp)

    numLst2 = result
    result = []

print(len(numLst2))
