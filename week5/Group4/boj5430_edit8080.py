# 1. R(reverse)가 추가 될 때마다 pop 할 방향을 뒤집음
# 2. D(delete)일 때 해당 위치에서 pop
# 3. 명령 종료 시 R이 지정한 방향에서 iterate 하게 pop 하고 출력

from collections import deque


def AC(p, n, deq):
    operator = 0
    size = n

    for i in range(len(p)):
        if p[i] == 'R':
            operator += 1
        elif p[i] == 'D':
            if size == 0:
                print("error")
                return
            else:
                deq.popleft() if operator % 2 == 0 else deq.pop()
                size -= 1

    print('[', end="")
    for i in range(size):
        print(deq.popleft(), end="") if operator % 2 == 0 else print(deq.pop(), end="")
        if i != size - 1:
            print(',', end="")
    print(']')

    return


if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        p = input()
        n = int(input())
        x = list(input().lstrip('[').rstrip(']').split(','))
        deq = deque(x)

        AC(p, n, deq)
