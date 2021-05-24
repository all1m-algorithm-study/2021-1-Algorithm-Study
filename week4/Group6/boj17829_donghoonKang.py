def makeSecondMaxes(list, width):
    arrayTwo = []
    for j in range(0, width, 2):
        arrayOne = []
        for k in range(0, width, 2):
            tmp = []
            tmp.append(list[j][k])
            tmp.append(list[j][k+1])
            tmp.append(list[j+1][k])
            tmp.append(list[j+1][k+1])
            tmp.sort()
            arrayOne.append(tmp[-2])
        arrayTwo.append(arrayOne)
    return arrayTwo


N = int(input())
numbers = []
for _ in range(N):
    numbers.append(list(map(int, input().split())))

myList = numbers[:]
width = N
result = None

while True:
    if width == 1:
        result = myList[0][0]
        break
    nextArray = makeSecondMaxes(myList, width)
    myList = nextArray
    width = width // 2

print(result)
