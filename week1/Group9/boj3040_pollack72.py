L = list()
for i in range(9):
    L.append(int(input()))

Sum = sum(L)
Left = Sum - 100
I = 0
J = 0
for i in range(9):
    for j in range(i+1, 9):
        if L[i]+L[j] == Left:
            I = i; J = j
for i in range(9):
    if i != I and i != J:
        print(L[i])