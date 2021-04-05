num, limit = map(int, input().split())
arr = list(map(int, input().split()))

arr_min = 0

for i in range(num):
    for j in range(i+1, num):
        for k in range(j+1, num):
            if arr[i] + arr[j] + arr[k] <= limit and arr[i] + arr[j] + arr[k] > arr_min:
                arr_min = arr[i] + arr[j] + arr[k]

print(arr_min)
