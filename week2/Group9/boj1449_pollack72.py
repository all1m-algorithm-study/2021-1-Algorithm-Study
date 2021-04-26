N, L = map(int,input().split())
Leaks = list(map(int, input().split()))
Leaks.sort()

count = 0
while True:
    first = Leaks[0]
    cover = first + (L-1)
    temp = False
    for i in range(len(Leaks)):
        if Leaks[i] > cover:
            Leaks = Leaks[i:]
            temp = True
            break
    count += 1
    if temp == False: break
print(count)