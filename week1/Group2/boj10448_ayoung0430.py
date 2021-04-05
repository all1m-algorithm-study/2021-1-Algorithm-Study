trinum=[]
for i in range(1,50):
    trinum.append(i*(i+1)/2)

K=[]    
N=int(input())
for _ in range(N):
    K.append(int(input()))



able=[]

for m in trinum:
    for n in trinum:
        for o in trinum:
            if m+n+o<=1000:
                able.append(m+n+o)

for j in K:
    for p in able:
        if p==j:
            print(1)
            break
    else:
        print(0)
