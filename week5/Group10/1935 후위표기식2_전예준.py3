stack_num=[]
stack_all=[]
stack_no_duplicates=[]
stack_final=[]
n=int(input())
s=input()
for _ in range(n):
    stack_num+=[input()]
for i in s:
    if i.isalpha():
        if not i in stack_no_duplicates:
            stack_no_duplicates.append(i)
for i in s:
    if i.isalpha():
        stack_all.append(stack_num[stack_no_duplicates.index(i)])
    else:
        stack_all.append(i)
stack_all=stack_all[::-1]
while len(stack_all)>0:
    if stack_all[-1].isdigit():
        stack_final.append(stack_all.pop())
    else:
        a=stack_final.pop()
        b=stack_final.pop()
        c=stack_all.pop()
        stack_final.append(str(eval(b+c+a)))
print('%.2f'%float(stack_final.pop()))