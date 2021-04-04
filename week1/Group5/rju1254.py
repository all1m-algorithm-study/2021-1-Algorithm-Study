s = input()
l = len(s)

for i in range(0, l):
    find = True
    for j in range(i, (l - i) // 2 + i):
        if(s[j] != s[l + i - j - 1]):
            find = False
            break
    if(find): 
        print(l + i)
        break