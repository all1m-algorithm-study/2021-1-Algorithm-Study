n, m = map(int, input().split())
s = []

def dfs(first):
    if len(s) == m:
        print(' '.join(map(str, s)))  # 공백을 넣어주며 리스트 요소를 붙이고 문자열로 바꾸어 반환
        return

    for i in range(first, n + 1):  # 앞의 숫자가 뒤의 숫자보다 작은 경우를 제외하기 위한 설정
        if i not in s:
            s.append(i)
            dfs(i + 1)
            s.pop()  # 맨 마지막 요소 돌려주고 그 요소는 삭제(이렇게 해야지 s가 다시 비워짐)

dfs(1)