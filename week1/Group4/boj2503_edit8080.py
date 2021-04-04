# 1. 서로 다른 세자리 숫자 전부와 입력한 질문값을 비교
# 2. 모든 질문을 통과한 수를 카운팅
#
# 시간복잡도 = O(n)


def isDifferent(num):
    letterCount = [0 for i in range(10)]

    for i in range(3):
        if int(num[i]) == 0:
            return False
        letterCount[int(num[i])] += 1

    for i in range(1, 10):
        if letterCount[i] >= 2:
            return False

    return True


def numberBaseball(check, question, score):
    checkScore = 0

    # 스트라이크 체크
    for i in range(3):
        if check[i] == question[i]:
            checkScore += 10

    # 볼 체크
    for i in range(3):
        for j in range(3):
            if i != j and check[i] == question[j]:
                checkScore += 1

    if checkScore == score:
        return 1
    return 0


n = int(input())
answer = [False for i in range(1000)]

for i in range(n):
    question, strike, ball = input().split(' ')
    score = 10 * int(strike) + int(ball)

    for i in range(100, 1000):
        if isDifferent(str(i)):
            answer[i] += numberBaseball(str(i), str(question), score)

answerCount = 0
for i in range(100, 1000):
    if answer[i] == n:
        answerCount += 1

print(answerCount)
