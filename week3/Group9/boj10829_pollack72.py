N = int(input())

L = []
def binary(n):
    if n//2 != 0:
        if n % 2 == 0:
            L.append(0)
            return binary(n//2)
        else:
            L.append(1)
            return binary(n//2)
    else:
        L.append(1)
        return

binary(N)

a = 0
for i in range(len(L)):
    a += L[i]*10**i
print(a)