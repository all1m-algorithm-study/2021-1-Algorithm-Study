def binary(n):
    if n == 0 or n == 1:
        return str(n)
    if n % 2 == 0:
        return binary(int(n / 2)) + '0'
    return binary(int((n - 1) / 2)) + '1'


N = int(input())
print(binary(N))