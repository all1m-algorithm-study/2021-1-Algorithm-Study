N,M = map(int,input().split())
arr = list(map(int,input().split()))
ans = []
for i in range (N):
    for j in range (i+1,N):
        for k in range (j+1,N):
            ans.append(arr[i]+arr[j]+arr[k])
a = 0
for i in range(len(ans)):
    if ans[i] <= M :
        if ans[i]>a:
            a= ans[i]
print(a) 