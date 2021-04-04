array = list(map(int, input().split()))
end=False
for x in range(-999, 1000):
    for y in range(-999, 1000):
        if array[0]*x+array[1]*y == array[2]:
            if array[3]*x+array[4]*y == array[5]:
                print(x, y)
                end = True
                exit(0)
