n,m=map(int,input().split())
stack=[i for i in range(1,n+1)]
final=[]
i=m-1
while len(final)<n:
    i%=len(stack)
    final+=[stack.pop(i)]
    i+=m-1
print('<'+str(final).strip('[]')+'>')