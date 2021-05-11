import sys
input = sys.stdin.readline
CHOOSE = 6

def comb(k, S, pos, lotto, ans):
    if len(lotto) == CHOOSE:
        ans.append(sorted(lotto))
        return
    elif (k - pos) + len(lotto) < CHOOSE:
        return  # 6개가 선택될 가망성이 없다. (남은 숫자 개수 + 고른 숫자의 수) < 6

    # 안 포함
    comb(k, S, pos+1, lotto, ans)
    # 포함
    comb(k, S, pos+1, lotto+[S[pos]], ans)

if __name__ == '__main__':
    while True:
        ip = list(map(int, input().strip().split()))
        k = ip[0]
        if k == 0:
            break

        S, ans = ip[1:], []
        comb(k, S, 0, [], ans)

        for l in sorted(ans):
            for x in l:
                print(x, end=' ')
            print()
        print()
