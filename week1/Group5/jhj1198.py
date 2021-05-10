'''
not yet solved
그리디 알고리즘 적용 가능
항상 가장 작은 넓이 삼각형을 만드는 점 (abc)에서 b 제외하면 됨. (볼록다각형이니까)
1. 제외 할 점 찾기( find_deleted_dot 이용) ~ 넓이 계산해서 가장 작은 삼각형을 이룰때 가운데 점 제거
2. 3개 남을때까지 반복
3. 넓이 구하기
4. 넓이 구할 때는  사선공식 사용
'''


def calc_triangle_area(A, B, C):
    area = 0.5*(A[0]*B[1] + B[0]*C[1] + C[0]*A[1] - B[0]*A[1] - C[0]*B[1] - A[0]*C[1])

    if area > 0:
        return area
    else:
        return area*(-1)


def find_deleted_dot(num_dot, dot_list): #점의 개수가 4개 이상일때만 사용가능

    area_list = {}

    for idx in range(0, num_dot):
        if idx == num_dot - 1:
            area = calc_triangle_area(dot_list[idx], dot_list[0], dot_list[1])
            area_list[area] = 0
        elif idx == num_dot - 2:
            area = calc_triangle_area(dot_list[idx], dot_list[idx + 1], dot_list[0])
            area_list[area] = idx + 1
        else:
            area = calc_triangle_area(dot_list[idx], dot_list[idx + 1], dot_list[idx + 2])
            area_list[area] = idx + 1

    print(area_list)
    min_area = min(list(area_list.keys()))
    print(min_area)

    return area_list[min_area]


def cut_polygon():

    n = int(input())
    dot_list = []
    for i in range(n):
        x, y = map(int, input().split())
        dot_list.append((x, y))

    num_dot = len(dot_list)

    while num_dot > 3:
        dot_list.pop(find_deleted_dot(num_dot, dot_list))
        num_dot -= 1

    print(dot_list)
    return calc_triangle_area(dot_list[0], dot_list[1], dot_list[2])


print(cut_polygon())