def triangle(a,d,b,e,c,f):
    front=a*e+b*f+c*d
    rear=d*b+e*c+f*a
    area=0.5*(front-rear)

    return abs(area)

N=int(input())
x_list=list(0 for i in range(0,N))
y_list=list(0 for i in range(0,N))

for i in range(0,N):
    x_list[i],y_list[i]=map(int,input().split())

Is_max=0
max=0
area=0

for i in range(0,N-2):
    for j in range(i+1,N-1):
        for k in range(j+1,N):
            Is_max=triangle(x_list[i],y_list[i],x_list[j],y_list[j],x_list[k],y_list[k])
            if Is_max!=-1 and Is_max>max:
                max=Is_max

print(max)


    
