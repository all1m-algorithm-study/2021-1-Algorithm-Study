import sys
def list_chunk(lst, n):
    return [lst[i:i+n] for i in range(0, len(lst), n)]
def kanto (c,n) :
    if len(c) == 1:
        return c
    else :
        c1 = list_chunk(c,3**(n-1))
        for i in range(len(c1[1])) :
            c1[1][i] = ' '
        if len(c1) == 1 :
            return c1[0]+c1[1]+c1[2]
        else :
            return kanto(c1[0],n-1) + c1[1] + kanto(c1[2],n-1)

while True:
    try :
        n=input()
        n=int(n)
        c=[]
        for i in range(3**n) :
            c.append('-')
        c=kanto(c,n)
        for i in range(len(c)-1) :
            print(c[i],end='')
        print(c[len(c)-1])
    except EOFError :
        break