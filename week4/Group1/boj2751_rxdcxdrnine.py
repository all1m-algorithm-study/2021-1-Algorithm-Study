n = int(input())
arr = []
for _ in range(n):
    arr.append(int(input()))


def merge_arr(a, b):
    result = []
    i = 0
    j = 0

    while i < len(a) and j < len(b):
        if a[i] < b[j]:
            result.append(a[i])
            i += 1
        else:
            result.append(b[j])
            j += 1

    if i == len(a):
        while j < len(b):
            result.append(b[j])
            j += 1
    else:
        while i < len(a):
            result.append(a[i])
            i += 1

    return result


def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    left = merge_sort(arr[:len(arr) // 2])
    right = merge_sort(arr[len(arr) // 2:])
    result = merge_arr(left, right)
    return result


arr = merge_sort(arr)
for element in arr:
    print(element)