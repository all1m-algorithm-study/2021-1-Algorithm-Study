def binary(nums,a) :
    if nums >1 :
        nums_n=nums//2
        a.append(nums%2)
        return binary(nums_n,a)
    else :
        a.append(nums)
        return a
nums=input()
nums = int(nums)
a=[]
c=binary(nums,a)
c.reverse()
for i in range(len(c)) :
    print (c[i], end='')