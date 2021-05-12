def tueMos(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    elif n % 2 == 0:
        return tueMos(n//2)
    else:
        return 1-tueMos(n//2)


k = int(input())
print(tueMos(k-1))
