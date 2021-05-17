def f(A):
    bc=0
    c=0
    i=0
    while i<len(A):
        bc=0
        if (i+1)<len(A) and A[i+1]=='(':
            bc+=1
            for j in range(i+2,len(A)):
                if A[j]=='(':
                    bc+=1
                if A[j]==')':
                    bc-=1
                if bc==0:
                    break
            c+=int(A[i])*f(A[i+2:j])
            i=j+1
        else:
            c+=1
            i+=1
    return c
a=input()
print(f(a))