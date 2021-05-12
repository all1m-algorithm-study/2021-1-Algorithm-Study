num = int(input())
arr_list = []
for _ in range(num):
    arr_list.append(input())


def recursion(arr):
    if len(arr) == 1:
        return True

    left = arr[:len(arr) // 2]
    right = arr[len(arr) // 2 + 1:]

    for i in range(len(arr) // 2):
        if arr[i] == arr[(len(arr) - 1) - i]:
            return False

    if recursion(left) and recursion(right):
        return True
    else:
        return False


for arr in arr_list:
    result = recursion(arr)
    if not result:
        print("NO")
    else:
        print("YES")
