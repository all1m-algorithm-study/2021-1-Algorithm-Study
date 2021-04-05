numbers = [int(input()) for _ in range(9)]
fakeFlag = False

for i in numbers:
    copyNumbersOne = numbers[:]
    copyNumbersOne.remove(i)
    for j in copyNumbersOne:
        copyNumbersTwo = copyNumbersOne[:]
        copyNumbersTwo.remove(j)
        if sum(copyNumbersTwo) == 100:
            fakeFlag = True
            break
    if fakeFlag == True:
        break

for k in copyNumbersTwo:
    print(k)
