import sys

def recursion(num):
  if num == 1:
    print('-', end='')
  else:
    recursion(num // 3)
    print(' ' * (num // 3), end='')
    recursion(num // 3)

# 입력 받기
for num in sys.stdin:
  recursion(3 ** int(num))
  print() 