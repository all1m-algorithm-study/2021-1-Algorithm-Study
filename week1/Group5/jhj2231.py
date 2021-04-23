'''
분해합
'''

def decomposite_num(num):
    answer = num
    while num > 0:
        answer += num % 10
        num //= 10

    return answer


def find_creator():

    n = int(input())
    digit_n = int(len(str(n))) #n 자릿수 구하기

    if n < 18:
        for test_num in range(1, n):
            if decomposite_num(test_num) == n:
                return test_num
        return 0

    else:
        for test_num in range(n - 9*digit_n, n):
            if decomposite_num(test_num) == n:
                return test_num
        return 0


print(find_creator())