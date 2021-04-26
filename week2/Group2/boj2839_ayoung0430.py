a=int(input())
sugar=[10000,10000]

for i in range(0,a):
    for j in range(0,a):
        if 5*i+3*j==a and int(sugar[0])+int(sugar[1])>i+j:
            sugar[0]=i
            sugar[1]=j
if sum(sugar)==20000:
    print(-1)
else:
    print (sum(sugar))
