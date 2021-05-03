a,b,c=map(int,input().split())
t=a
for i in bin(b)[3:]:
    t=(t*t%c,a*t*t%c)[int(i)]
print(t%c)