def f(A):
    if len(A)==0:
        return 0
    if A[0] == '(':
        bp = 0
        for j in range(len(A)):
            if A[j] == '(':
                bp += 1
            elif A[j] == ')':
                bp -= 1
            if bp == 0:
                break
        if j == 1:
            return 2 + f(A[2:])
        else:
            return 2 * f(A[1:j]) + f(A[j:])
    else :
        bp = 0
        for j in range(len(A)):
            if A[j] == '[':
                bp += 1
            elif A[j] == ']':
                bp -= 1
            if bp == 0:
                break
        if j == 1:
            return 3 + f(A[2:])
        else:
            return 3 * f(A[1:j]) + f(A[j+1:])
stack1=[]
stack2=[]
S=input()
isSpossible=True
for i in range(len(S)):
    if S[i]=='(':
        stack1.append(S[i])
    elif S[i]==')':
        if len(stack1)==0 or stack1[-1]==')':
            isSpossible=False
            break
        else:
            stack1.pop()
    elif S[i] == '[':
        stack2.append(S[i])
    elif S[i] == ']':
        if len(stack2) == 0 or stack2[-1] == ']':
            isSpossible=False
            break
        else:
            stack2.pop()
if len(stack1)!= 0 or len(stack2)!= 0:
    isSpossible=False
if isSpossible:
    print(f(S))
else:
    print(0)