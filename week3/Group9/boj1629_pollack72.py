# example
A, B, C = map(int, input().split())

def power(A, B, C):
    if B == 0:
        return 1
    elif B % 2 == 0:
        return (power(A, B//2, C) ** 2) % C
    else:
        return ((power(A, B//2, C) ** 2) * A) % C

print(power(A, B, C))