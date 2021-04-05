A = input()
breaker=0
l=len(A)
pos=[]

for i in range(l):
    breaker=0
    for j in range(((l-i)//2)+1):
        if A[i+j]!=A[-1-j]:
            breaker=1
            break
        
    if breaker==0:
        print(l+i)
        break
