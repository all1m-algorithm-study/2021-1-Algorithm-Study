import sys

arr = []
N = int(input())
pop_index = 0
# 리스트 특성 상 del, pop, remove 등은 삭제 후 복사 -> O(n)
# https://chancoding.tistory.com/35
# https://j-ungry.tistory.com/187
for _ in range(N):
    s = sys.stdin.readline().split()
    if s[0] == 'push':
        arr.append(int(s[1]))
    elif s[0] == 'pop':
        if len(arr) == pop_index:
            print(-1)
        else:
            print(arr[pop_index])
            pop_index += 1
    elif s[0] == 'size':
        print(len(arr) - pop_index)
    elif s[0] == 'empty':
        print(int(len(arr) == pop_index))
    elif s[0] == 'front':
        if len(arr) == pop_index:
            print(-1)
        else:
            print(arr[pop_index])
    elif s[0] == 'back':
        if len(arr) == pop_index:
            print(-1)
        else:
            print(arr[-1])
