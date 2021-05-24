n=int(input())
k=0
L=''
while n>0:
    n,k=divmod(n,2)
    L+=str(k)
print(L[::-1])