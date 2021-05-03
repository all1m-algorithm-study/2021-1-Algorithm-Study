N = int(input())
M = N // 5

five, three = 0, 0
flag = False

while M != 0:
    Ncopy = N
    Ncopy = Ncopy - M*5
    if Ncopy % 3 == 0:
        five = M
        three = Ncopy // 3
        break
    M -= 1

if M == 0:
    flag = True

if flag == True and N % 3 == 0:
    print(N//3)
elif flag == True and N % 3 != 0:
    print(-1)
else:
    print(five+three)
