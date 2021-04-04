L1 = [i for i in str(input())]
n = len(L1)

import copy
for i in range(n):
    L2 = copy.deepcopy(L1)
    L2.extend([L1[i-j-1] for j in range(i)])
    N = len(L2)
    temp = 1
    for k in range(int(N/2)+1):
        if L2[k] != L2[N-k-1]:
            temp = 0
            break
    if temp == 1: break

print(N)
