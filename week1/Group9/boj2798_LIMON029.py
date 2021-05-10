arr = []
NM=input().split(" ")
N=int(NM[0])
M=int(NM[1])
count=0
arr = input().split(" ")
for i in range(N):
    arr[i]=int(arr[i])
    count = count + 1

sum=0
for i in range(count-2):
    for j in range(i+1,count-1):
        for k in range(j+1,count):
            if arr[i]+arr[j]+arr[k] > M:
                continue
            else :
                sum = max(sum, arr[i]+arr[j]+arr[k])

print(sum)