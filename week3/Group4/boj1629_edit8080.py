# 1. 절반으로 쪼개가며 곱한다 (곱하는 횟수가 홀수면 따로 한 번 더 곱해준다)
# 2. 10^11 % 12 => (10*(10^5)*(10^5)) %12
#
# 시간복잡도 = O(log n)

def remainder(a, b, c):
    if b == 1:
        return a % c

    mul = a % c
    if b % 2 == 0:
        return remainder(mul*mul, b // 2, c) % c
    else:
        return a * remainder(mul*mul, b // 2, c) % c


a, b, c = map(int, input().split(" "))
print(remainder(a, b, c))
