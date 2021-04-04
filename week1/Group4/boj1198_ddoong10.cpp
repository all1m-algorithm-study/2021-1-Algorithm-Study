def tri(a,d,b,e,c,f):
    first = (a*e)+(b*f)+(c*d)
    second = (d*b)+(e*c)+(f*a)
    re = (first-second)*0.5
    if re >=0:
        return re
    else :
        return re*-1
n = int(input())
i= 0
a=0
b=0
c=0
answer=0
x = [0]*n
y = [0]*n
while i < n :
    x[i],y[i] = map(int, input().split())
    i=i+1
while a < n :
    b = 0
    a= a+1
    while b < n:
        c = 0
        b= b+1
        while c < n:
            c = c+1
            if answer <= (tri(x[a-1],y[a-1],x[b-1],y[b-1],x[c],y[c])) :
                answer = (tri(x[a-1],y[a-1],x[b-1],y[b-1],x[c],y[c]))
print(answer)
