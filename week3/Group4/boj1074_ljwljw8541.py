#boj1074_ljwljw8541

N,r,c=map(int,input().split())
def Z(i,j,k):
    sum = 0
    if i == 1:
        if j == 0:
            if k == 0:
                sum += 0
                return 0
            elif k == 1:
                sum += 1
                return 1
        elif j == 1:
            if k == 0:
                sum += 2
                return 2
            elif k == 1:
                sum += 3
                return 3 
    elif i>1:
        if j >=2**(i-1):
            if k >=2**(i-1):
                sum += 3*(2**(2*i-2))
                return sum + Z(i-1,j-2**(i-1),k-2**(i-1))
            else:
                sum += 2*(2**(2*i-2))
                return sum + Z(i-1,j-2**(i-1),k)
        else:
            if k >=2**(i-1):
                sum += 1*(2**(2*i-2))
                return + sum + Z(i-1,j,k-2**(i-1))
            else:
                sum += 0
                return sum + Z(i-1,j,k)
    
print(Z(N,r,c))

    
