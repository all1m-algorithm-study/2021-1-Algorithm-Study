def isThereDifference(startPointX, startPointY, width):
    falseFlag = False
    for i in range(width):
        for j in range(width):
            if myList[startPointX+i][startPointY+j] != myList[startPointX][startPointY]:
                falseFlag = True
                break
        if falseFlag == True:
            break
    if falseFlag == True:
        return True
    else:
        return False


def sliceBitMap(startPointX, startPontY, width):
    if isThereDifference(startPointX, startPontY, width) == True:
        half = width // 2
        sliceBitMap(startPointX, startPontY, half)
        sliceBitMap(startPointX, startPontY+half, half)
        sliceBitMap(startPointX+half, startPontY, half)
        sliceBitMap(startPointX+half, startPontY+half, half)
    else:
        if myList[startPointX][startPontY] == 0:
            global white
            white += 1
        else:
            global blue
            blue += 1


N = int(input())
myList = []
for _ in range(N):
    tmp = list(map(int, input().split()))
    myList.append(tmp)

white = 0
blue = 0
sliceBitMap(0, 0, N)

print(white)
print(blue)
