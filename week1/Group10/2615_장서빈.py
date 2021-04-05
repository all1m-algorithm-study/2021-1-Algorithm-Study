def case1(a, i, j): # 세로 
    if a[i][j] == a[i][j+1] == a[i][j+2] == a[i][j+3] == a[i][j+4]:
        if a[i][j] != 0:
            return [i, j]

def case2(a,i,j): # 가로
    if a[i][j] == a[i+1][j] == a[i+2][j] == a[i+3][j] == a[i+4][j]:
        if a[i][j] != 0:
            return [i, j]

def case3(a,i,j): # 대각선 \
    if a[i][j] == a[i+1][j+1] == a[i+2][j+2] == a[i+3][j+3] == a[i+4][j+4]:
        if a[i][j] != 0:
            return [i, j]

def case4(a,i,j): # 대각선 /
    if a[i][j] == a[i+1][j-1] == a[i+2][j-2] == a[i+3][j-3] == a[i+4][j-4]:
        if a[i][j] != 0:
            return [i, j]

list = [[int(x) for x in input().split()]for y in range(19)]

find = []
find2 = []
find3 = []
find4 = []
f_sort = []

for i in range(0, 19):
    for j in range(0, 19):
        if j < 15:
            if case1(list,i,j) != None:
                find.append(case1(list,i,j))
        if i < 15:
            if case2(list,i,j) != None:
                find2.append(case2(list,i,j))
        if i < 15 and j < 15:
            if case3(list,i,j) != None:
                find3.append(case3(list,i,j))
        if i < 15 and j > 3:
            if case4(list,i,j) != None:
                find4.append(case4(list,i,j))
    
for i in range(int(len(find))): # 6목 이상 제외
    if_6 = [-1,1]
    count = 0
    x = find[i][0]
    y = find[i][1]
    for j in if_6:
        if [x,y+j] in find:
            count += 1
    if count == 0:
        f_sort.append(find[i])

for i in range(int(len(find2))): # 6목 이상 제외
    if_6 = [-1,1]
    count = 0
    x = find2[i][0]
    y = find2[i][1]
    for j in if_6:
        if [x+j,y] in find2:
            count += 1
    if count == 0:
        f_sort.append(find2[i])

for i in range(int(len(find3))): # 6목 이상 제외
    if_6 = [-1,1]
    count = 0
    x = find3[i][0]
    y = find3[i][1]
    for j in if_6:
        for k in if_6:
            if [x+j,y+k] in find3:
                count += 1
    if count == 0:
        f_sort.append(find3[i])

for i in range(int(len(find4))): # 6목 이상 제외
    if_6 = [-1,1]
    count = 0
    x = find4[i][0]
    y = find4[i][1]
    for j in if_6:
        for k in if_6:
            if [x+j,y+k] in find4:
                count += 1
    if count == 0:
        f_sort.append([x+4,y-4])

if f_sort == []: # 결과가 나지 않을 경우
    print(0)
else:            # 누군가가 이길 경우
    print(list[f_sort[0][0]][f_sort[0][1]])
    print(f_sort[0][0]+1, f_sort[0][1]+1)