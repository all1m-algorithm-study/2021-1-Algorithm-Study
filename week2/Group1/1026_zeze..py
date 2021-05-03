num = int(input())
sum = 0
arr_A = list(map(int, input().split()))
arr_B = list(map(int, input().split()))

arr_A.sort()
arr_B.sort(reverse=True)

for i in range(num):
    sum += arr_A[i] * arr_B[i]
print(sum)