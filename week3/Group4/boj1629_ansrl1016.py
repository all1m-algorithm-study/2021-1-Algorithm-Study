def power(a,b,c) :
    if b<=2 :
        return a**b%c
    elif b%2==1 :
        return (power(a,b//2,c)**2)*a %c
    elif b%2==0 :
        return (power(a,b//2,c)**2) % c

a, b, c = map(int,input().split())
answer = power(a,b,c)
print(answer)