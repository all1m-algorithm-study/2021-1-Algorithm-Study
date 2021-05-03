s = []
def combination(i, n, m, a):
    if(m == 0): 
        print(a)
        return
    while(i < n - m + 1):
        combination(i + 1, n, m - 1, a + str(s[i]) + " ")
        i += 1

while True:
    l = list(map(int, input().split()))
    n = l[0]
    if(n == 0): break
    s = l[1:]

    combination(0, n, 6, "")
    print()
