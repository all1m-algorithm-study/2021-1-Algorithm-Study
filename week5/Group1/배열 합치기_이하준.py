input()

arr = []

for _ in range(2):
    arr= arr+(list(map(int, input().split())))

arr.sort()
for i in range(len(arr)):
    if i == len(arr)-1:
        print(arr[i])
    else:
        print(arr[i], end=' ')
