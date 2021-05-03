# 1. length 를 0으로 초기화한 후 괄호를 만날 때까지 length 를 1씩 증가시킨다.
# 2. "("를 만나면 k 값을 설정하고 1로 돌아간다.
# 3. ")"를 만나면 length 를 return 한다.
# 4. 모든 탐색이 중첩되면 안되므로 check 를 통해 각 위치의 검사유무를 판단한다.
#
# 시간복잡도 = O(n^2) (n: 문자열의 길이) =>  (모든 문자열의 각 위치에서 끝까지 탐색)

s = input()
check = [False for _ in range(len(s))]


def unzip(start):
    length = 0

    for i in range(start, len(s)):
        if s[i] == "(" and not (check[i]):
            check[i] = True
            k = int(s[i - 1])
            length += k * unzip(i + 1) - 1  # 괄호 길이 빼주기

        elif s[i] == ")" and not (check[i]):
            check[i] = True
            return length

        elif not (check[i]):
            check[i] = True
            length += 1

    return length


print(unzip(0))
