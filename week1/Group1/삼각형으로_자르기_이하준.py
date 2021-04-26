l=[]
S=0
max_S=0
for i in range(int(input())):
    l.append([i]+list(map(int,input().split())))

for xn, x1, y1 in l:
    for yn, x2, y2 in l[xn+1:]:
        for zn, x3, y3 in l[yn+1:]:
            S=abs(0.5*(x1*y2+x2*y3+x3*y1-x1*y3-x3*y2-x2*y1))
            if S>max_S or max_S==0:
                max_S=S

print(max_S)
