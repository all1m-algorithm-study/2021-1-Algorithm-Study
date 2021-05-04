for i in range(int(input())):
    N = int(input())
    def tr(n):
        return n*(n+1)/2

    max = 1
    k=0
    while True:
        if N <= max*(max+1)/2:
            break
        max += 1

    for x in range(1,max+1):
        for y in range(1,max+1):
            for z in range(1,max+1):
                a=tr(x)+tr(y)+tr(z)
                if a==N:
                    k=1
                    break
    print(k)
