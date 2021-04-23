def sorting(room):
    count = 0
    start = 0

    # 끝나는 시간이 다음 시작시간보다 작거나 같나면 회의 가능
    for i in room:
        if i[0] >= start:
            start = i[1]
            count += 1
    print(count)


num = int(input())
room = []
count = 0

for i in range(num):
    room.append(list(map(int, input().split())))

# 회의 시작 시간 정렬
room.sort(key=lambda x: x[0])
# 회의 종료 시간 정렬
room.sort(key=lambda x: x[1])

sorting(room)
