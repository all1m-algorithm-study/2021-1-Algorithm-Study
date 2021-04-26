N = int(input())

def Result(a, b):
    a1 = (a//100)%10
    a2 = (a//10)%10
    a3 = a%10
    b1 = (b//100)%10
    b2 = (b//10)%10
    b3 = b%10
    A = [a1, a2, a3]; B = [b1, b2, b3]
    strike = 0
    ball = 0
    for i in range(3):
        for j in range(3):
            if A[i] == B[j]:
                if i == j: strike += 1
                else: ball += 1
    return strike, ball

L = list()
for i in range(1, 10):
    for j in range(1, 10):
        if i == j: continue
        for k in range(1, 10):
            if i == k: continue
            if j == k: continue
            L.append(100*i+10*j+k)

import copy
for i in range(N):
    x, s, b = map(int, input().split())
    L1 = list()
    for j in L:
        if Result(j, x) == (s, b):
            L1.append(j)
    L = copy.deepcopy(L1)

print(len(L))