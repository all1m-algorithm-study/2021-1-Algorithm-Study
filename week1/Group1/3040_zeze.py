arr = []
for i in range(9):
    arr.append(int(input()))

sum_arr = sum(arr)

for i in range(9):
    for j in range(i+1):
        if sum_arr - (arr[i] + arr[j]) == 100:
            remove_val1 = arr[i]
            remove_val2 = arr[j]

arr.remove(remove_val1)
arr.remove(remove_val2)

for i in range(7):
    print(arr[i])
