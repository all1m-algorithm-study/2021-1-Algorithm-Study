# strategy : 1부터 입력한 수까지 확인 (brute force)
#
# 시간복잡도 : <= O(nlogn)  (밑이 10인 상용 로그)

def routine(num):
    for check in range(1, num):
        constructor = check
        digit = check

        while digit:
            constructor += int(digit % 10)
            digit = int(digit / 10)

        if constructor == num:
            return check

    return 0

n = int(input())
print(routine(n))
