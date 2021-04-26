t = int(input())
triNumLst = [int((i*(i+1))/2) for i in range(1, 45)]

for test in range(t):
    flag = True
    testNum = int(input())
    for rng in range(len(triNumLst)):
        if triNumLst[rng] >= testNum:
            triNumSlice = triNumLst[:rng]
            break
        else:
            triNumSlice = triNumLst
    
    for i in triNumSlice:
        if flag == False:
            break
        for j in triNumSlice:
            if flag == False:
                break
            for k in triNumSlice:
                if testNum == (i + j + k):
                    print(1)
                    flag = False
                    break
    if flag:
        print(0)
