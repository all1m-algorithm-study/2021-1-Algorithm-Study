# 1. 2로 나누어가면서 발생하는 나머지를 가장 앞에 저장한다 (like 스택)
#
# 시간복잡도 = O(log n)

def toBinary(ans, num):
    if num == 0:
        return ans

    if num % 2 == 0:
        ans = "0" + ans
    else:
        ans = "1" + ans

    return toBinary(ans, num // 2)


n = int(input())
print(toBinary("", n))
