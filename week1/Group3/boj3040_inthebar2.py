a = list()
for i in range(0, 9):
    a.append(int(input()))

s = sum(a)

found = 0
for i in range(0, 9):
    for j in range(i+1, 9):
        if s - (a[i] + a[j]) == 100:
            found = 1
            break
    if found:
        break

for k in range(0, 9):
    if k != i and k != j:
        print(a[k])