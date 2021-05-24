stack = []
line = []
N = int(input())
students = list(map(int, input().split()))

while len(students) > 0:
    if len(stack) == 0:
        stack.append(students.pop(0))
    else:
        if stack[-1] > students[0]:
            stack.append(students.pop(0))
        else:
            line.append(stack[-1])
            students.pop(0)

while len(stack) > 0:
    line.append(stack[-1])
    stack.pop(-1)
if line == sorted(line):
    print("Nice")
else:
    print("Sad")
