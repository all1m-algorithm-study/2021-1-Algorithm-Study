stack = []
answer = []

N = int(input())
for _ in range(N):
    oneLine = input()
    command3 = oneLine[:3]
    if command3 == "pus":
        num = int(oneLine[5:])
        stack.append(num)
        continue
    elif command3 == "pop":
        if len(stack) == 0:
            answer.append(-1)
            continue
        else:
            tmp = stack.pop()
            answer.append(tmp)
            continue
    elif command3 == "siz":
        answer.append(len(stack))
        continue
    elif command3 == "emp":
        if len(stack) == 0:
            answer.append(1)
            continue
        else:
            answer.append(0)
            continue
    elif command3 == "top":
        if len(stack) == 0:
            answer.append(-1)
            continue
        else:
            top = stack[-1]
            answer.append(top)
            continue

for i in range(len(answer)):
    tmp = answer[i]
    print(tmp)
