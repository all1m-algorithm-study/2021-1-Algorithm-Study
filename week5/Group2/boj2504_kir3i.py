import sys
input = sys.stdin.readline

if __name__ == '__main__':
    s = input().strip()
    st = [('x', 0)]
    for c in s:
        if c == '(' or c == '[':
            st.append((c, 0))
        elif c == ')':
            pair, val = st.pop()
            if pair != '(':
                print(0)
                break
            val = val*2 if val != 0 else 2
            nxt = st.pop()
            st.append((nxt[0], nxt[1]+val))
        elif c == ']':
            pair, val = st.pop()
            if pair != '[':
                print(0)
                break
            val = val * 3 if val != 0 else 3
            nxt = st.pop()
            st.append((nxt[0], nxt[1] + val))
        # print(f'After {c}, stack: {st}')
    else:
        if len(st) > 1:
            print(0)
        else:
            print(st[0][1])
