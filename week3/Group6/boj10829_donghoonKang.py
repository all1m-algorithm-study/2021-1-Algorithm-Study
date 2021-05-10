N = int(input())
result = ''


def toBinary(n):
    if n == 0:
        return '0'
    elif n == 1:
        return '1'
    else:
        return toBinary(n//2) + str(n % 2)


if N % 2 == 0:
    result = toBinary(N) + result
else:
    result = toBinary(N//2) + '1' + result

print(int(result))
