n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

i = 0
j = 0
while True:
    if(i >= n):
        for x in b[j:] : print(x, end=' ')
        break
    elif(j >= m):
        for x in a[i:] : print(x, end=' ')
        break
    if(a[i] <= b[j]):
        print(a[i], end=' ')
        i += 1
    else:
        print(b[j], end=' ')
        j += 1