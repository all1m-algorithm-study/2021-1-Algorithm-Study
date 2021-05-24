def cantor(n):
    if n == 0 :
        return '-'
    elif n >= 1 :
        return cantor(n-1) + ' '*(3**n-1) + cantor(n-1)


while True :
    try :
        n = int(input())
        answer = cantor(n)
        print(answer)
    except :
        break
