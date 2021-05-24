N = int(input())
numbers = [int(input()) for _ in range(N)]


def merge(A, B):
    pointA, pointB = 0, 0
    N = len(A)
    M = len(B)
    result = []

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


def merge_sort(numbers):
    if len(numbers) == 1:
        return numbers
    mid = len(numbers)//2
    leftList = merge_sort(numbers[:mid])
    rightList = merge_sort(numbers[mid:])
    return merge(leftList, rightList)


for i in merge_sort(numbers):
    print(i)
