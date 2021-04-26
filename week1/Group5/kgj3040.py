dwarf=list()

for i in range(0,9):
    dwarf.append(int(input()))

def sum(first,second):
    Is_hun=0;
    for i in range(0,9):
        if i==first or i==second:
            continue
        Is_hun+=dwarf[i]
    return Is_hun

Not_dwarf1=0
Not_dwarf2=0
breaker=0
for i in range(0,9):
    for j in range(0,9):
        if i!=j:
            checking=sum(i,j)
            if checking==100:
                Not_dwarf1=i
                Not_dwarf2=j
                breaker=1
                break
    if breaker==1:
        break


for i in range(0,9):
    if i!=Not_dwarf1 and i!=Not_dwarf2:
        print(dwarf[i])



