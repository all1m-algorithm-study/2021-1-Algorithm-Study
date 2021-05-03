r = 0

def remainder(a, b, c):
    if(b == 1): return r
    elif(b % 2 == 0): return pow(remainder(a, b // 2, c), 2) % c
    elif(b % 2 == 1): return (pow(remainder(a, b // 2, c), 2) % c * r) % c

a, b, c = map(int, input().split())

r = a % c

print(remainder(a, b, c))