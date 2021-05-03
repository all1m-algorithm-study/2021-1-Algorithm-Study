
def Cantor_set(x):
    if x == 0:
        return '-'
    elif x >= 1:
        return Cantor_set(x-1) +' '*(3**(x-1)) + Cantor_set(x-1)

while True:
    try:
        N = int(input())
        print(Cantor_set(N))
    except:
        break