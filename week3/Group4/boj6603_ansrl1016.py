import sys
input = sys.stdin.readline

def lotto(k, start, selected):
    if len(selected) == 6:
        print(*selected)
    elif start <= k-1:
        selected.append(s[start])
        lotto(k, start+1, selected)
        selected.pop()
        lotto(k, start+1, selected)

while True:
    arr = list (map(int, input().split()))
    k = arr[0]
    if k== 0:
        break
    s = arr[1:]
    lotto(k, 0, [])
    print()