def cantoring(n):
    if(n == 0): return '-'
    else:
        return cantoring(n-1) + ' ' * pow(3, n - 1) + cantoring(n-1)

while True:
    try:
        n = int(input())
        cantoring(n)
    except EOFError:
        break