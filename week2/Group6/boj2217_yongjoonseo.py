# 로프를 이용하여 물체를 들어올릴 수 있다.
# k개의 로프로 중량 w인 물체를 들면 각 로프엔 w/k만큼의 중량이 실린다

# 출력: 로프들을 이용하여 들어올릴 수 있는 물체의 최대 중량

# 체크할 조건
# 1 <= N <= 100000 개의 로프
    # 한 줄 한 줄이라 입력이 많다
# 모든 로프를 사용할 필요는 없다.
# 모든 로프가 들 수 있는 물체의 중량이 서로 다를 수도 있다.

# 가장 약한 로프부터 (로프 중량) * (감당할 수 있는 로프 수)로 갱신해본다. 


import sys
input = sys.stdin.readline

def solution(N):
    lst = []
    for _ in range(N):
        lst.append(int(input()))
    lst.sort()
    maxval = 0
    for i in range(N):
        temp = (N - i) * lst[i]
        if temp > maxval:
            maxval = temp
    print(maxval)

if __name__ == '__main__':
    solution(int(input()))