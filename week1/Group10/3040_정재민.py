array=[]
for i in range(9):
    x=int(input())
    array.append(x)

answer=0
value=0
for i in range(9):
    if answer==1:
        break
    for j in range(9):
        if answer==1:
            break
        for k in range(9):
            if answer==1:
                break
            for l in range(9):
                if answer==1:
                    break
                for m in range(9):
                    if answer==1:
                        break
                    for n in range(9):
                        if answer==1:
                            break
                        for o in range(9):
                            if answer==1:
                                break
                            for q in [i,j,k,l,m,n,o] :
                                for p in [i,j,k,l,m,n,o]:
                                    if q==p:
                                        value=value+1

                            if value ==7:
                                if array[i]+array[j]+array[k]+array[l]+array[m]+array[n]+array[o]==100:
                                    answer=1    
                                    print(array[i])
                                    print(array[j])
                                    print(array[k])
                                    print(array[l])
                                    print(array[m])
                                    print(array[n])
                                    print(array[o])
                            value =0
                            
