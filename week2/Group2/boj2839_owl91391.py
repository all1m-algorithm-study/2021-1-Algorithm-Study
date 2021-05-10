nk = int(input())
tot=0
s5 = nk%5
n=nk
if s5 ==0 :
    tot = nk//5
else :
    for i in range (n) :
        nk = nk-3
        if nk >0 :
            a = nk%5
            if a ==0 :
                tot = (nk//5) + i +1
                break
            else :
                continue
        elif nk ==0:
            tot = i+1
            break
        else :
            tot = -1
            break
print(tot)