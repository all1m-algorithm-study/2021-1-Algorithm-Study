def triangle_area(tri):
    x1, y1, x2, y2, x3, y3 = tri[0][0], tri[0][1], tri[1][0], tri[1][1], tri[2][0], tri[2][1]
    return abs(0.5 * (((x2-x1)*(y3-y1))-((x3-x1)*(y2-y1))))

N = int(input())
coord = list()
for _ in range(N):
    coord.append(list(map(int, input().split(' '))))

max_area = 0
for i in range(N):
    for j in range(i + 1, N):
        for k in range(j + 1, N):
            # print([coord[i], coord[j], coord[k]])
            area = triangle_area([coord[i], coord[j], coord[k]])
            if area > max_area:
                max_area = area
print(max_area)
