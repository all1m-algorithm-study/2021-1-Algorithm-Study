def dhWay(theString):
    stack = []
    length = len(theString)

    if length == 1:
        return True
    mid = length // 2
    for i in range(mid):
        if theString[i] == theString[length-i-1]:
            return False
    return dhWay(theString[:mid]) and dhWay(theString[mid+1:])


N = int(input())
cases = []
for _ in range(N):
    cases.append(input())

for k in cases:
    if dhWay(k):
        print('YES')
    else:
        print('NO')
