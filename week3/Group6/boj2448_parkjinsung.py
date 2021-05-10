import math
n = int(input())
base_star = ["  *  ", " * * ", "*****"]

cnt = int(math.log(n/3, 2))

def make_triangle(base_star, n, cnt):
    if cnt == 0:
        return base_star
    new_star = []
    space = ' ' * (int(n/2))
    for i in range(len(base_star)):
        new_star.append(space + base_star[i] + space)
    for i in range(len(base_star)):
        new_star.append(base_star[i] + ' ' + base_star[i])
    cnt -= 1
    return make_triangle(new_star, n*2, cnt)

star = make_triangle(base_star, 6, cnt)
for i in range(len(star)):
    print(star[i].replace('\0', ''), sep='') 
