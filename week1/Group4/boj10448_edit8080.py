# 1. 배열에 삼각수를 인덱스로 한 지점에 True 저장, 나머지에는 False 저장 (해시맵)
# 2. 주어진 수 - (삼각수 2개의 합) 을 1에서 만든 해시맵을 통해 확인한다.
#
# 시간복잡도 : O(k * n^2) (K:input)

def triNum(num):
    return int(num * (num + 1) / 2)


def checkTriNum(num, isTriNum):
    for i in range(1, 1001):
        for j in range(1, 1001):
            if num - (triNum(i) + triNum(j)) > 0 and isTriNum[num - (triNum(i) + triNum(j))]:
                return True
    return False


isTriNum = [False for i in range(triNum(1001))]
for i in range(1, 1001):
    isTriNum[triNum(i)] = True

n = int(input())
for i in range(n):
    checkNum = int(input())
    print(1) if checkTriNum(checkNum, isTriNum) else print(0)
