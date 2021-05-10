N = int(input())
arr=[]
p=10000000
ok = False
for a in range(0,10):
    for b in range(0,10):
        for c in range(0,10):
            for d in range(0,10):
                for e in range(0,10):
                    for f in range(0,10):
                        sum=a+b+c+d+e+f
                        if a*100000+b*10000+c*1000+d*100+e*10+f+sum==N:
                            arr.append(a*100000+b*10000+c*1000+d*100+e*10+f)
                            ok = True
if ok: print(min(arr))
else: print(0)    


