def make_seq(S,N,M,list,realM):
    if M==0:
        for i in range(0,realM):
            print(list[i],end=' ')
        print()
        return
    else:
        for i in range(S,N-M+2):
            list[realM-M]=i
            make_seq(i+1,N,M-1,list,realM)

a,b=map(int,input().split())
list=[0 for i in range(b)]
make_seq(1,a,b,list,b)
        
        