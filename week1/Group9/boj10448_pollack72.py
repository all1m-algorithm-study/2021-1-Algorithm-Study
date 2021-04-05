Triangle = [i*(i+1)/2 for i in range(1, 45)]
Possible = []

for i in range(44):
    for j in range(44):
        for k in range(44):
            Possible.append(Triangle[i]+Triangle[j]+Triangle[k])

T = int(input())
L = [int(input()) for i in range(T)]
for i in L:
    if i in Possible: print('1')
    else: print('0')