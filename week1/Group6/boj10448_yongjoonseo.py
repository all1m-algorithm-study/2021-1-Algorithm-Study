# 출력: 주어진 자연수가 3개의 삼각수의 합으로 표현되는지 여부

# 체크할 조건
# 3개의 삼각수가 모두 다를 필요는 없다
# 3 <= 자연수 K <= 1000

# 44*45 // 2 == 990, n은 최대 44
# 44 ** 3 == 85184
# 삼각수를 모두 구해놓고 중복을 포함해서 3개 뽑아본다
    # 모두 더했을 때 K가 되면 그 순간 1 출력

def solution(K, dp):
    for a in range(1, 45):
        if dp[a] >= K: break
        for b in range(1, 45):
            if dp[b] >= K: break
            for c in range(1, 45):
                if dp[c] >= K: break
                if dp[a] + dp[b] + dp[c] == K:
                    print(1)
                    return
    print(0)

if __name__ == '__main__':
    dp = [0] * 45
    dp[1] = 1
    for i in range(2, 45):
        dp[i] = dp[i-1] + i
    for _ in range(int(input())):
        solution(int(input()), dp)