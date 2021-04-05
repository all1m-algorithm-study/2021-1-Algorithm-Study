N = int(input())

numbers = []
strike = []
ball = []
possible = list(range(123, 988))

# 입력값 받아오는 반복문
for _ in range(N):
    temp = list(map(int, input().split()))
    numbers.append(temp[0])
    strike.append(temp[1])
    ball.append(temp[2])

# 두 개의 세자리수를 받아 strike와 ball 횟수 리턴


def strikeORball(A, B):
    a = [0, 0, 0]
    b = [0, 0, 0]
    ballCount = 0
    strikeCount = 0

    # 자릿수별로 나눠둔다.
    a[0] = A // 100
    a[1] = (A % 100) // 10
    a[2] = (A % 100) % 10
    b[0] = B // 100
    b[1] = (B % 100) // 10
    b[2] = (B % 100) % 10

    # ball 횟수 세기
    if (a[0] == b[1]) or (a[0] == b[2]):
        ballCount += 1
    if (a[1] == b[0]) or (a[1] == b[2]):
        ballCount += 1
    if (a[2] == b[0]) or (a[2] == b[1]):
        ballCount += 1

    # strike 횟수 세기
    if a[0] == b[0]:
        strikeCount += 1
    if a[1] == b[1]:
        strikeCount += 1
    if a[2] == b[2]:
        strikeCount += 1

    # strike과 ball의 횟수를 리스트로 리턴
    result = [strikeCount, ballCount]
    return result


# 완전탐색 반복문
for i in range(123, 988):
    # 세자리 자연수 i를 자릿수별로 나눠둔다.
    copyi = [0, 0, 0]
    copyi[0] = i // 100
    copyi[1] = (i % 100) // 10
    copyi[2] = (i % 100) % 10

    # 세자리 숫자가 서로 모두 달라야 하고 0이 있으면 안된다. 그렇지 않으면 '답으로 possible한 리스트'에서 제외
    if (copyi[0] != copyi[1]) and (copyi[1] != copyi[2]) and (copyi[2] != copyi[0]) and (copyi[0] != 0) and (copyi[1] != 0) and (copyi[2] != 0):
        for j in range(N):
            result = strikeORball(numbers[j], i)
            # strike와 ball의 횟수를 동시에 만족하지 못하면 이 역시 '답으로 possible한 리스트'에서 제외
            if (result[0] != strike[j]) or (result[1] != ball[j]):
                if i in possible:
                    possible.remove(i)
    else:
        possible.remove(i)

# 위 결과 남겨진 possible 리스트의 원소의 갯수 출력
print(len(possible))
