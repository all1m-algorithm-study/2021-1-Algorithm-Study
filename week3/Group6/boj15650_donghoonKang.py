N, M = map(int, input().split())


def mySelect(n, m):
    if m == 1:
        myList = []
        for i in range(1, n+1):
            myList.append([i])
        return myList
    else:
        myList = mySelect(n, m-1)
        copyList = []
        for j in myList:
            indx = j[0]
            for k in range(1, n+1):
                if k != indx and k > indx:
                    copyList.append([indx, k])
