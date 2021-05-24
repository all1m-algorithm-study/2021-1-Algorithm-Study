def z(n, r, c, result):
    if(n == 0): return result

    if(r >= 2 ** (n - 1)):
        r -= 2 ** (n - 1)
        result += 4 ** (n - 1) * 2
    if(c >= 2 ** (n - 1)):
        c -= 2 ** (n - 1)
        result += 4 ** (n - 1)
    
    return z(n - 1, r, c, result)

n, r, c = map(int, input().split())
print(z(n, r, c, 0))