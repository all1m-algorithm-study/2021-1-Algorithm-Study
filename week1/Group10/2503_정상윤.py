import sys
from itertools import permutations

n = int(input())
arr = ['1','2','3','4','5','6','7','8','9']

cnt = 0

per_list = list(permutations(arr,3))
baseball = []

for i in range(n):
    baseball.append(list(map(int,sys.stdin.readline().split())))


for i in range(504):
    able_num = per_list[i]
    passed = 0
    for j in range(n):
        s = 0
        b = 0
        baseball_num = list(str(baseball[j][0]))
        

        for k in range(3):
            if able_num[k] == baseball_num[k]:
                s += 1
            elif able_num[k] == baseball_num[(k+1)%3] or able_num[k] == baseball_num[(k+2)%3]:
                b += 1

        
        if s!=baseball[j][1] or b!= baseball[j][2]:
            flag = False
            break
        else:
            passed += 1
        # print(s,b)

    if passed == n:
        cnt += 1
        
print(cnt)
        
