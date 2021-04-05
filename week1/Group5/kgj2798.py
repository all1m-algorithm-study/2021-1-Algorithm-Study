cards=list()
N,M=map(int,input().split())
cards=list(map(int,input().split()))

first=0
second=0
third=0
Is_max=0
max=0

for i in range(0,N-2):
    for j in range(i+1,N-1):
        for k in range(j+1,N):
            sum=cards[i]+cards[j]+cards[k]
            if sum<=M:
                Is_max=sum
                if Is_max>max:
                    max=Is_max

print(max)
