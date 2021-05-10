n,m=map(int,input().split())
arr=list(map(int,input().split()))
summax = 0

for i in range (n-2):
    for j in range (i+1,n-1):
        for k in range (j+1,n):
            if arr[i] + arr[j] + arr[k]<=m:
                if summax >= arr[i] + arr[j] + arr[k]:
                    continue
                else:
                    summax = arr[i] + arr[j] + arr[k]
            else:
                continue

print(summax)