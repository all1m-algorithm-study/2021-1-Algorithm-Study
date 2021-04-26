tri_num = []

n = int(input())

for i in range(1,45):
    tri_num.append(int(i*(i+1)/2))

def is_(n):
    for i in range(44):
        for j in range(44):
            for k in range(44):
                if tri_num[i] + tri_num[j] + tri_num[k] == n:
                    return 1
    return 0
    
for i in range(n):
    x = int(input())
    print(is_(x))