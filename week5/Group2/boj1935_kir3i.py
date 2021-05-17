import sys
input = sys.stdin.readline

def calc(x, operand):
    st = []
    for c in x:
        if c == '+':
            b, a = st.pop(), st.pop()
            st.append(a+b)
        elif c == '*':
            b, a = st.pop(), st.pop()
            st.append(a*b)
        elif c == '-':
            b, a = st.pop(), st.pop()
            st.append(a-b)
        elif c == '/':
            b, a = st.pop(), st.pop()
            st.append(a/b)
        else:
            st.append(operand[ord(c) - ord('A')])
    return st[-1]



if __name__ == '__main__':
    N = int(input().strip())
    x = input().strip()
    operand = [int(input().strip()) for _ in range(N)]

    print(f'{calc(x, operand):.2f}')
