A, B, C = map(int, input().split())


def AxxB(a, b):
    if b == 0:
        return 1
    elif b == 1:
        return a % C
    else:
        tmp = AxxB(a, b//2)
        if b % 2 == 0:
            return tmp * tmp % C
        else:
            return tmp * tmp * a % C


print(AxxB(A, B))
