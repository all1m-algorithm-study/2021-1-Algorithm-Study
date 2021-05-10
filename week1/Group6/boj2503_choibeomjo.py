import sys
from itertools import permutations

n = [1, 2, 3, 4, 5, 6, 7, 8, 9]

num = list(permutations(n, 3))	# 순열로 3개씩 뽑음

t = int(sys.stdin.readline())
for _ in range(t):
    test, s, b = map(int, sys.stdin.readline().split())
    test = list(str(test))
    removed_cnt = 0     # 배열에서 제거된 튜플 개수

    # num : 3개 리스트
    leng = len(num)
    for i in range(leng):
        s_cnt = b_cnt = 0   # 스트 개수, 볼 개수 0 초기화
        i -= removed_cnt

        for j in range(3):
            test[j] = int(test[j])
            if test[j] in num[i]:
                if j == num[i].index(test[j]):
                    s_cnt += 1
                else:
                    b_cnt += 1

        if s_cnt != s or b_cnt != b:
            num.remove(num[i])      # 스트 개수, 볼 개수 다르면 배열에서 제거
            removed_cnt += 1

print(len(num))
