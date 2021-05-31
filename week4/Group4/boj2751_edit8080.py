# 1. 중앙 지점을 기준으로 재귀적으로 분할(left, right), size==1 일 때 분할 종료
# 2. left 와 right 두 배열값을 비교하면서 merge
#
# 시간복잡도 = O(nlg(n))

n = int(input())
num = [int(input()) for _ in range(n)]


def merge(left_list, right_list):
    left_index = 0
    right_index = 0
    left_size = len(left_list)
    right_size = len(right_list)
    ret = []

    while left_index < left_size and right_index < right_size:
        if left_list[left_index] < right_list[right_index]:
            ret.append(left_list[left_index])
            left_index += 1
        else:
            ret.append(right_list[right_index])
            right_index += 1

    if right_index == right_size:
        while left_index < left_size:
            ret.append(left_list[left_index])
            left_index += 1

    elif left_index == left_size:
        while right_index < right_size:
            ret.append(right_list[right_index])
            right_index += 1

    return ret


def divide(num_list, size):
    if size == 1:
        return num_list
    left = divide(num_list[0:size // 2], size // 2)
    right = divide(num_list[size // 2:], (size + 1) // 2)

    return merge(left, right)


ans = divide(num, n)
for i in range(len(ans)):
    print(ans[i])
