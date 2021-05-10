def sol(x,y,z):
    if y == 0:
        return 1 % z
    elif y % 2 == 0:
        return (sol(x,y//2,z)**2) % z
    else:
        return ((sol(x,y//2,z)**2)% z *x)%z
A,B,C = map(int, input().split())
print(sol(A,B,C))