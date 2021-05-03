def main():
    num = int(input())
    global arr
    arr = []
    hanoi(num, 1, 3)
    print(len(arr))
    for move in arr:
        print(move[0],move[1])


def hanoi(num, _from, _to):
    if num == 1:
        arr.append([_from, _to])
        return
    mid = 6-_from-_to
    hanoi(num-1, _from, mid)
    arr.append([_from, _to])
    hanoi(num-1, mid, _to)


if __name__ == "__main__":
    main()
