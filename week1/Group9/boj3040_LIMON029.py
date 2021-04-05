array = []
sum = 0
for i in range(9):
    item = int(input())
    array.append(item)
    sum += item

for i in range(9):
    for j in range(9):
        if i==j:
            continue
        elif sum - array[i] - array[j] == 100:
            array[i]= -1
            array[j]= -1

    for a in array:
        if a != -1:
            print(a)