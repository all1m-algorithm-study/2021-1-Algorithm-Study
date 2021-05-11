def cantor(s):
    index_len = int(len(s)/3)
    
    s1 = s[:index_len]
    s2 = " "*index_len
    s3 = s[index_len*2:]
    result = s1 + s2 + s3
    
    if len(result) == 3:
        print(result, end = "")
    else:
        cantor(s1)
        cantor(s2)
        cantor(s3)
        
while True:
    try:
        n = int(input())
        s = "-"*(3**n)
        if n == 0:
            print("-")
            continue
        cantor(s)
        print()

    except EOFError:
        break
