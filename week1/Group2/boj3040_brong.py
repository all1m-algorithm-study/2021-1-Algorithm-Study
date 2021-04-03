n = 9
array = [int(input()) for i in range(n)]
sum=0
a,b=-1,-1
for i in range(n):
    sum += array[i]
for j in range(n):
    for k in range(j+1,n) :
        if array[j] + array[k] == sum - 100 : 
            a,b = j, k
ans = [array[i] for i in range(n) if i!=a and i!=b]
for x in ans:
    print(x)
