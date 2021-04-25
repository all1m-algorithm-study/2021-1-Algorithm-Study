n = int(input())

ropeLst = []
for i in range(n):
    ropeLst.append(int(input()))
    
ropeLst.sort(reverse = True)

tempMax = 0
for i in range(n):
    if tempMax < ropeLst[i]*(i+1):
        tempMax = ropeLst[i]*(i+1)
        
print(tempMax)
