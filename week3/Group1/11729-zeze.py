def hanoi(num, _from, tmp, to):
    if num == 1:
        print(_from, to, end = ' ')
        print()
    else:
        hanoi(num - 1, _from, to, tmp)
        print(_from, to, end = ' ')
        print()
        hanoi(num - 1, tmp, _from, to)

hanoi_num = int(input())
print(pow(2,hanoi_num) - 1)
hanoi(hanoi_num, 1, 2, 3)
    