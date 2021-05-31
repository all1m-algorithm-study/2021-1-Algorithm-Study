k = int(input())


def thus_morse(k):
    if k == 0:
        return 0
    if k == 1:
        return 1
    else:
        if k % 2 == 0:
            return thus_morse(k // 2)
        if k % 2 == 1:
            return 1 - thus_morse(k // 2)


print(thus_morse(k - 1))