# 서류 성적 면접 성적 중 적어도 하나가 다른 지원자보다 떨어지지 않는 사람 선발

# 출력: 선발할 수 있는 신입사원의 최대 인원 수
    # 각 테케마다 한 줄에 하나

# 체크할 조건
# 1 <= N <= 100000 (지원자 숫자)

# 서류 성적 순위 숫자 낮은 순으로 정렬
    # 순위 숫자가 낮을수록 성적이 좋다
# 순회하면서 나왔던 면접 성적 중 가장 높은 것보다 성적이 낮으면 떨어진다.

import sys
input = sys.stdin.readline


def solution(N):
    lst = []
    for _ in range(N):
        lst.append(list(map(int, input().split())))
    lst.sort()

    max_rank = N+1
    cnt = 0
    for _, interview in lst:
        if interview <= max_rank:
            cnt += 1
            max_rank = interview
    print(cnt)

if __name__ == '__main__':
    for _ in range(int(input())):
        solution(int(input()))