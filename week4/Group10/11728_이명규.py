N, M = map(int, input().split())
arr1, arr2, arr = [], [], []
for n in input().split():
    arr1.append(int(n))
for n in input().split():
    arr2.append(int(n))
a, b = 0, 0
while a != N and b != M:
    if arr1[a] < arr2[b]:
        arr.append(arr1[a])
        a += 1
    else:
        arr.append(arr2[b])
        b += 1
if a == N:
    arr += arr2[b:]
else:
    arr += arr1[a:]
for num in arr:
    print(num, end=' ')
