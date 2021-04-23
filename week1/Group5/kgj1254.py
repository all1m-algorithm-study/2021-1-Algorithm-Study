A=list(input())
temp=list(A)
correct=0

def Is_pen(array):
    flag1=0
    flag2=0
    for j in range(0,len(array)//2):
        if array[j]==array[len(array)-1-j]:
            flag1+=1
    if flag1==len(array)//2:
        flag2=1
    return flag2

for i in range(0,len(A)):
    correct=Is_pen(temp)
    if correct==0:
        temp=list(A)
        for j in range(i,-1,-1):
            temp.append(A[j])
    elif correct==1:
        break

print(temp)

print(len(temp))
