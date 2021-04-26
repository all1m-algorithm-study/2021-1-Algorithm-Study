# 0개 이상의 문자를 추가해서 팰린드롬 만들기

# 출력: 만들 수 있는 가장 짧은 팰린드롬의 길이

# 체크할 조건
# len(S) <= 1000

# 1. 각 문자의 양 옆을 살핀다.
    # 양 옆 문자가 다르면 넘어간다.
    # 같으면 다른 문자가 나오거나 끝이 나올 때까지 ++, --하며 살핀다.
        # 서로 다른 문자가 나오면 넘어간다.
# 2. 문자열의 첫 부분이나 끝에 다다르면 남아있는 부분의 길이를 더해준다.
    # 남은게 없으면 0을 더한다.
# 가장 짧은 팰린드롬의 길이로 갱신한다.


# def solution(string):
#     min_length = float('inf')
#     for i in range(len(string)):
#         left, right, gap = i-1, i+1, 1
#         while left >= 0 and right < len(string) and string[left] == string[right]:
#             left -= 1
#             right += 1
#             gap += 1
#         if left < 0 or right >= len(string):
#             length = len(string) * 2 - (gap * 2 - 1)
#             min_length = min(min_length, length)
#     print(min_length)

# if __name__ == '__main__':
#     solution(input())

# 반례: eeeffe
    # 하나의 알파벳을 중심으로 양 옆을 비교하다보니 ff처럼 붙어있는 경우를 찾지 못한다.


# 문자열을 뒤집은 후 문자열 끝까지 일치하는 순간의 길이를 구한다.

def solution(string):
    lst = list(string)
    lst.reverse()
    rev_string = ''.join(lst)
    
    for i in range(len(string)):
        for j in range(len(string)-i):
            if string[j+i] != rev_string[j]:
                break
        else:
            print(len(string) + i)
            return

if __name__ == '__main__':
    solution(input())
