N = int(input())
arith = input()
stack=[]
aa = [0] * N
for j in range(N) :
    aa[j] = int(input())
for i in arith :
    if 'A' <= i <= 'Z' :
        stack.append(aa[ord(i)-ord('A')])
    else :
        a1 = stack.pop()
        a2 = stack.pop()
        if i == '+' :
            stack.append(a1+a2)
        elif i == '-' :
            stack.append(a2-a1)
        elif i == '*' :
            stack.append(a1 * a2)
        elif i == '/' :
            stack.append(a2/a1)

print("{:.2f}".format(*stack))