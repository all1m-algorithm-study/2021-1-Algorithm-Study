def change_full_bin(index, k, limit_num):
    pos = list(map(int, bin(index)[2:]))
    while len(pos) < k:
        pos.insert(0, 0)
    if sum(pos) == limit_num:
        return pos
    return None

while True:
    num_lst = list(map(int, input().split()))
    k = num_lst[0]
    num_lst = num_lst[1:]
    result = []
    result_lst = []

    for i in range(2**k):
        pos = change_full_bin(i, k, 6)
        if pos:
            for j in range(k):
                num = num_lst[j] * pos[j]
                if num == 0:
                    continue
                elif num != 0:
                    result.append(num)
            result_lst.append(result) 
            result = []
        
    result_lst.sort(reverse = False)
    for i in result_lst:
        print(*i)
    print()
    if k == 0:
        break
