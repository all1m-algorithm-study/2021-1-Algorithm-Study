brackets = input()
stack = []
score = 0
for bracket in brackets:
    if bracket == "(" or "[":
        stack.append(bracket)
    elif bracket == ")" and len(stack) != 0 and stack[-1] == "(":
        stack.pop()
        score += 2
    elif bracket == "]" and len(stack) != 0 and stack[-1] == "[" :
        stack.pop()
        score += 3
    print(bracket)

#다 돌고나서 남은 원소 있을 때 0 출력