n = int(input())

points = []
for _ in range(n):
    points.append(list(map(int, input().split())))


def get_area(tri):
    # x_min, x_max = min(tri, key=lambda x: x[0])[0], max(tri, key=lambda x: x[0])[0]
    # y_min, y_max = min(tri, key=lambda x: x[1])[1], max(tri, key=lambda x: x[1])[1]
    # area = (x_max - x_min) * (y_max - y_min)
    #
    # mask = 0
    # mask += abs(tri[0][0] - tri[1][0]) * abs(tri[0][1] - tri[1][1]) / 2
    # mask += abs(tri[1][0] - tri[2][0]) * abs(tri[1][1] - tri[2][1]) / 2
    # mask += abs(tri[2][0] - tri[0][0]) * abs(tri[2][1] - tri[0][1]) / 2
    #
    # area -= mask

    area = abs(tri[0][0] * tri[1][1] + tri[1][0] * tri[2][1] + tri[2][0] * tri[0][1] -
               (tri[1][0] * tri[0][1] + tri[2][0] * tri[1][1] + tri[0][0] * tri[2][1])) / 2
    return area


res = 0
for i in range(len(points)):
    for j in range(i + 1, len(points)):
        for k in range(j + 1, len(points)):
            extracted = points[i], points[j], points[k]
            res = max(res, get_area(extracted))

print(res)