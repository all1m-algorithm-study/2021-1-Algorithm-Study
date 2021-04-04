dwarf=[]

for i in range(9):
    x=int(input())
    dwarf.append(x)

for i in range (9):
    for j in range (i+1,9):
        if sum(dwarf)-dwarf[i]-dwarf[j]==100:
            for k in range (0,9):
                if k!=i and k!=j:
                    print(int(dwarf[k]))
            break
        else:
            continue