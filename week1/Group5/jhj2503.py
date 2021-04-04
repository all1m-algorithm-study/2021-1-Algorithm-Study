def strike(n, N):
    rslt = 0

    if (n % 10 == N % 10): rslt += 1
    if ((n // 10) % 10 == (N // 10) % 10): rslt += 1
    if (n // 100 == N // 100): rslt += 1

    return rslt

def ball(n, N):
    arr1 = [n // 100, (n // 10) % 10, n % 10]
    arr2 = [N // 100, (N // 10) % 10, N % 10]
    rslt = 0

    if (arr1[0] == arr2[1] or arr1[0] == arr2[2]): rslt += 1
    if (arr1[1] == arr2[0] or arr1[1] == arr2[2]): rslt += 1
    if (arr1[2] == arr2[0] or arr1[2] == arr2[1]): rslt += 1

    return rslt

# 123부터 999까지 배열 만들기
arr = []
a = 123
for i in range(889):
    a1 = a // 100
    a2 = (a // 10) % 10
    a3 = a % 10

    if a1 == 0 or a2 == 0 or a3 == 0: arr.append(-1)
    elif a1 == a2 or a1 == a3 or a2 == a3: arr.append(-1)
    else: arr.append(a)

    a += 1

# 스트라이크와 볼 개수 비교하여 다르면 제외
n = int(input())
for i in range(n):
    N, s, b = map(int, input().split())
    for j in range(889):
        if arr[j] != -1:
            S = strike(arr[j], N)
            B = ball(arr[j], N)
            if s != S or b != B: arr[j] = -1

rslt = 0
for i in range(889):
    if arr[i] != -1: rslt += 1
print(rslt)