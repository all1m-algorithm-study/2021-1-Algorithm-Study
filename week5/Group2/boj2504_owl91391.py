import sys
input = sys.stdin.readline

bracket = str(input())
stack1 = []
stack2 = []
brac=[]
num=1
result = 0
for c in bracket :
    brac.append(c)
brac.pop()
for i in range(len(brac)) :
    if brac[i] =='(' :
        stack1.append('(')
        num *=2
    elif brac[i] == '[' :
        stack2.append('[')
        num *=3
    elif brac[i] == ')' :
        if len(stack1) == 0 :
            stack1 = [1]
            break
        else :
            if brac[i-1] == '(' :
                result += num
            stack1.pop()
            num /=2
    elif brac[i] == ']' :
        if len(stack2) == 0 :
            stack2 = [1]
            break
        else :
            if brac[i-1] == '[' :
                result += num
            stack2.pop()
            num /=3
if stack1 !=[] or stack2 != [] :
    print(0)
else :
    print(int(result))