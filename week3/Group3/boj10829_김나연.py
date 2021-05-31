def dec2bin(n):
    if n == 0:
        return
    dec2bin(n // 2)
    print(n % 2, end='')

n = int(input(''))
dec2bin(n)