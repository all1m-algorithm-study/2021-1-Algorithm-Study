bracket = input()
stack = []
check_stack = []

for i in bracket :                       #올바른 배열인지 확인
    if i == '(' :
        check_stack.append('(')
    elif i =='[' :
        check_stack.append('[')
    elif i == ')' :
        if check_stack and check_stack[-1] == '(' :
            check_stack.pop()
        else :
            check_stack.append(i)
    elif i == ']' :
        if check_stack and check_stack[-1] == '[' :
            check_stack.pop()
        else :
            check_stack.append(i)
    stack.append(i)

if len(check_stack) != 0 :
    print(0)

else :                                  #숫자 계산
    new_stack = []                         # 첫번째 반복문 : 붙어있는 괄호 숫자로 바꾸기 ; ()는 2로, []는 3으로
    m_dict = {'(' : ')', '[' : ']'}
    v_dict = {'(' : 2 , '[' : 3} 
    for i in range(len(stack)) :
        if len(new_stack) > 0 and new_stack[-1] in v_dict:
            if m_dict[new_stack[-1]] == stack[i] :
                tmp = new_stack[-1]
                new_stack.pop()
                new_stack.append(v_dict[tmp])
            else :
                new_stack.append(stack[i])
        else :
            new_stack.append(stack[i])

    stack = []
    m_sum = 0
    now = 0
    for i in range(len(new_stack)):         # 두번째 반복문 : 최종 계산
        if len(stack) ==  0 or new_stack[i] =='(' or new_stack[i] =='[':       # '(','[' 만나면 push
            stack.append(new_stack[i])
        elif new_stack[i] ==')' or new_stack[i] ==']':                         # ')',']' 만나면 짝이 맞는 괄호가 나올때까지 그 사이의 숫자 덧셈 / 짝을 맞나면 곱셈
            while stack :
                if stack[-1] in m_dict and m_dict[stack[-1]] == new_stack[i]:  
                    break
                a = stack.pop()
                now += int(a)
            if stack:                                                          
                now *= v_dict[stack[-1]]
                stack.pop()
            stack.append(now)
            now = 0

        else:                                                                  # 숫자 만나면 push                                         
            stack.append(new_stack[i])

    print(sum(stack))
