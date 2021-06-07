import sys

input = sys.stdin.readline

family_num = int(input())

first, goal = map(int, input().split())

connecting_num = int(input())

family_list = [[] for _ in range(family_num + 1)]
visted_list = [0] * (family_num + 1) # 가족이 1부터 시작하므로 가족 개수보다 하나 더 필요

for _ in range(connecting_num):
    one, two = map(int, input().split())
    family_list[one].append(two)
    family_list[two].append(one)

# print(family_list)

def dfs(before):
    # global family_one
    for i in family_list[before]:
        # one이 아니고 방문한 적이 없음
        if i != first and visted_list[i] == 0:
            # 처음 방문한 one부터 방문 개수가 하나 씩 증가
            visted_list[i] = visted_list[before] + 1
            dfs(i)

dfs(first)

if visted_list[goal] == 0:
    print(-1)
else:
    print(visted_list[goal])