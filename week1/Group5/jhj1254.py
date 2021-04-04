'''
팰린드롭인지 체크 (check_palindrome 함수 이용) count = 0
아니면 1번째 문자 제외, 펠린드롭인지 체크 아니면 count += 1
~이하반복
팰린드롭 나오면 루프 나오고, 현재 길이 + count 리턴
abba
0123
aba
012
aabccbad
01234567
'''

def check_palindrome(string):

    idxmax = len(string) - 1
    mid = (idxmax + 1) // 2

    for idx in range(mid, idxmax + 1):
        opposite_idx = idxmax - idx
        if string[idx] != string[opposite_idx]:
            return 0
    return 1  #팰린드롬이면 1 반환


def make_palindrome():

    string = input()
    len_string = len(string)
    count = 0

    while len(string) > 0:
        if check_palindrome(string) == 0:
            count += 1
            string = string[1:]
            continue
        break

    return len_string + count


print(make_palindrome())