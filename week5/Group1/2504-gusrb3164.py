def main():
    global s, match_idx
    s = input()
    match_idx = [0]*len(s)  # 해당 괄호의 닫힌 괄호 위치를 저장하는 배열
    stack = []
    match = {')': '(', ']': '['}
    # 유효성 검사 및 해당 괄호범위 저장
    for i in range(len(s)):
        # 열린괄호는 스택에 저장
        if s[i] in ['(', '[']:
            stack.append((s[i], i))
        else:
            # 닫힌괄호와 맞는 열린괄호가 없을 경우 유효성 실패
            if not stack or stack[-1][0] != match[s[i]]:
                print(0)
                return
            # 유효하다면 해당 닫힌괄호 위치를 열린괄호 인덱스에 저장
            match_idx[stack.pop(-1)[1]] = i
    # 괄호가 열린채로 끝나면 유효성 실패
    if stack:
        print(0)
        return
    # 전체 범위부터 재귀
    print(recur(0, len(s)-1))


def recur(start, end):
    if end-start < 1:
        return 1

    sum = 0
    # 현재 범위 내에서 더할수 있는 괄호들을 재귀
    while start < end:
        multi = 2
        if s[start] == '[':
            multi = 3
        # 양쪽 괄호 사이의 값을 재귀로 알아낸후 현재 괄호값을 곱함
        sum += multi*recur(start+1, match_idx[start]-1)
        # 닫힌 괄호의 다음부터 다시 탐색
        start = match_idx[start]+1
    return sum


if __name__ == "__main__":
    main()
