a, b, c = map(int, input().split())

def dnc(length):
    if length == 1:
        return a % c
    if length % 2 == 0:
        left = dnc(length // 2)
        return left * left % c
    else:
        left = dnc(length // 2)
        return left * left * a % c


print(dnc(b))