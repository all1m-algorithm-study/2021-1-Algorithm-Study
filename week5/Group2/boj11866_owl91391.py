n, k = map(int,input().split())
nums = []
for i in range(n) :
    nums.append(i+1)
stack=[]
j=k

while True:
    stack.append(nums[k-1])
    nums[k-1] = 'x'
    if nums == ['x'] * n :
        break
    for i in range(j) :
        k +=1
        if k > n :
            k=1
        while nums[k-1] == 'x' :
            k +=1
            if k > n :
                k = 1
print('<', end='')
for i in range(len(stack)-1) :
    print(stack[i] ,end=', ')
print(stack[-1],end='')
print('>')