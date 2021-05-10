def checking(number,How_many):
    flag=0
    for i in range(0,How_many):
        for j in range(0,How_many):
            for k in range(0,How_many):
                if number==(tri[i]+tri[j]+tri[k]):
                    flag=1
                    return flag
    return flag

T=int(input())
test=list()
tri=list()

for i in range(0,T):
    test.append(int(input()))

tri_number=0
a=1
while tri_number<1000:
    tri_number=(a*(a+1))/2
    tri.append(tri_number)
    a+=1
a-=1

for i in range(0,T):
    print(checking(test[i],a))

