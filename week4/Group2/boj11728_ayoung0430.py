N,M=map(int,input().split())
nN = list(map(int,input().split()))
nM = list(map(int,input().split()))

def sort(a,b):
    final=[]
    i=0; j=0
    while i < len(a) and j < len(b):
        if a[i]<b[j]:
            final.append(a[i])
            i+=1
        else:
            final.append(b[j])
            j+=1
    while i < len(a):
        final.append(a[i])
        i+=1
    while j < len(b):
        final.append(b[j])
        j+=1

    return final

answer=sort(nN,nM)
for i in range(len(answer)):
    print(answer[i], end=' ')