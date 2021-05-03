data = []
while True:
    try:
        data.append(int(input()))
    except:
        break

def Cantor(n):
    if n == 0:
        return '-'
    else:
        return Cantor(n-1)+' '*(3**(n-1))+Cantor(n-1)

for i in data:
    print(Cantor(i))