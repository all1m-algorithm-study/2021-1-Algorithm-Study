N = int(input())
A = list(map(int, input().split(' ')))
B = list(map(int, input().split(' ')))

C = sorted(A)
D = sorted(B, reverse=True)

sum = 0
for i in range(N):
    sum += C[i] * D[i]
print(sum)