# 3개의 연속된 점을 선택하여 삼각형 만든 후 다각형에서 제외

# 출력: 마지막 남은 삼각형의 넓이의 최댓값

# 만들 수 있는 모든 삼각형의 넓이 구해서 최댓값 갱신


# 1

def area(dot1, dot2, dot3):
    a, b = dot1
    c, d = dot2
    e, f = dot3
    return abs(((a*d + c*f + e*b) - (c*b + e*d + a*f)) / 2)

def solution(N):
    maxval = -1
    dots = [list(map(int, input().split())) for i in range(N)]
    for i in range(N-2):
        for j in range(i+1, N-1):
            for k in range(j+1, N):
                maxval = max(maxval, area(dots[i], dots[j], dots[k]))
    print(maxval)

if __name__ == '__main__':
    solution(int(input()))


# 2

from itertools import combinations

def area(dot1, dot2, dot3):
    a, b = dot1
    c, d = dot2
    e, f = dot3
    return abs(((a*d + c*f + e*b) - (c*b + e*d + a*f)) / 2)

def solution(N):
    maxval = -1
    dots = [list(map(int, input().split())) for i in range(N)]
    for dot1, dot2, dot3 in combinations(dots, 3):
        maxval = max(maxval, area(dot1, dot2, dot3))
    print(maxval)

if __name__ == '__main__':
    solution(int(input()))


# 3

def combinations(arr, start, r):
    for i in range(start, len(arr)-r+1):
        if r == 1:
            yield [arr[i]]
        else:
            for rest in combinations(arr, i+1, r-1):
                yield [arr[i]] + rest

def area(dot1, dot2, dot3):
    a, b = dot1
    c, d = dot2
    e, f = dot3
    return abs(((a*d + c*f + e*b) - (c*b + e*d + a*f)) / 2)

def solution(N):
    maxval = -1
    dots = [list(map(int, input().split())) for i in range(N)]

    for dot1, dot2, dot3 in combinations(dots, 0, 3):
        maxval = max(maxval, area(dot1, dot2, dot3))
    print(maxval)

if __name__ == '__main__':
    solution(int(input()))