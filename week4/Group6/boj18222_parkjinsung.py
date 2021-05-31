n = int(input())

def find_scope(n):
    idx = 0
    while True:
        if n > 2**idx and n <= 2**(idx+1):
            break
        idx += 1
    return idx

if n != 1:
    idx = find_scope(n)

num_lst = [0, 1]

if n == 1:
    print(0)
elif n == 2:
    print(1)
else:
    for i in range(1, idx+1):
        new_idx = find_scope(n)
        n -= 2**new_idx
        if n == 1 or n == 2:
            if num_lst[n-1] == 1 and i%2 == 1:
                print(0)
                break
            elif num_lst[n-1] == 1 and i%2 == 0:
                print(1)        
                break
            elif num_lst[n-1] == 0 and i%2 == 1:
                print(1)        
                break
            elif num_lst[n-1] == 0 and i%2 == 0:
                print(0)        
                break
