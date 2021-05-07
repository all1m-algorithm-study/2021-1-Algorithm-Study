N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
A.sort()
B.sort()


def merge(A, B):
    pointA, pointB = 0, 0
    result = []
    if N >= M:
        mini = M
    else:
        mini = N
    while pointA < N and pointB < M:
        if A[pointA] >= B[pointB]:
            result.append(B[pointB])
            pointB += 1
        else:
            result.append(A[pointA])
            pointA += 1
    while pointA < N:
        result.append(A[pointA])
        pointA += 1
    while pointB < M:
        result.append(B[pointB])
        pointB += 1
    return result


answer = merge(A, B)
for i in answer:
    print(i, end=' ')
