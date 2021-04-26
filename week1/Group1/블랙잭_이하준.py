k=0
s, N = map(int,input().split())
l = list(map(int,input().split()))
max=0
for x in range(s):
    for y in range(x+1,s):
        for z in range(y+1,s):
            a=l[x]+l[y]+l[z]
            if a>max and a<=N:
                max=a
print(max)
