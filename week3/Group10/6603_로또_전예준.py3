for i in open(0):
    n=int(i)
    p='-'
    for j in range(n):
        p=p+' '*len(p)+p
    print(p)