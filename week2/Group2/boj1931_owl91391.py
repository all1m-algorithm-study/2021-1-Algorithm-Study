n= int(input())
c_time = sorted([tuple(map(int,input().split())) for _ in range(n)], key =lambda x:(x[1],x[0]))
cnt=end=0
for start,e in c_time :
    if start >=end :
        cnt+=1
        end = e
print(cnt)