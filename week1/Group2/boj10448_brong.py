T = int(input())
arr = [int(input()) for i in range(T)]
dic=[]
for i in range(1,45):
    for j in range(i,45):
        for k in range(j,45):
            dic.append((i**2+i)//2 + (j**2+j)//2 + (k**2+k)//2)

for x in range(T):
    a=0
    for i in range(len(dic)):
        if arr[x] == dic[i]:
            print(1)
            a=1
            break
    if a==0: print(0)


