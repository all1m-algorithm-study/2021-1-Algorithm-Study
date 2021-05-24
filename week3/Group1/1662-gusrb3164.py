def main():
    global s
    global s_idx
    s = str(input())
    s_idx = [0]*len(s)
    stack = []
    for i in range(len(s)):
        if s[i] == '(':
            stack.append(i)
        elif s[i] == ')':
            s_idx[stack.pop(-1)] = i
    print(recur(0, len(s)))


def recur(startIdx, endIdx):
    result = 0
    global s
    i = startIdx
    while i < endIdx:
        if s[i] == '(':
            result += int(s[i-1])*recur(i+1, s_idx[i])-1
            i = s_idx[i]+1
        else:
            result += 1
            i += 1
    return result


if __name__ == "__main__":
    main()
