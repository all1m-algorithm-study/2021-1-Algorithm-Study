N = int(input())
def howmany(x):
    if x==1 or x==2 or x==4 or x==7:
        return -1
    elif x==3 or x==6 or x==9 or x==12:
        return x//3
    elif x%5==0:
        return x//5
    else:
        for i in range(N//3):
            if (N-3*i)%5 ==  0:
                return (N-3*i)//5+i
print(howmany(N))
