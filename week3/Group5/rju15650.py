def combination(i, n, m, s):
    if(m == 0): 
        print(s)
        return
    while(i < n - m + 2):
        combination(i + 1, n, m - 1, s + str(i) + " ")
        i += 1

n, m = map(int, input().split())

combination(1, n, m, "")