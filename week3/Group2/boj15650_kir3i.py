import sys
input = sys.stdin.readline

def comb(N, M, pos, perm, ans):
    if len(perm) == M:
        ans.append(sorted(perm))
        return
    elif pos == N+1:
        return

    # 안 포함
    comb(N, M, pos+1, perm, ans)
    # 포함
    comb(N, M, pos+1, perm + [pos], ans)

if __name__ == '__main__':
    N, M = map(int, input().strip().split())
    ans = []
    comb(N, M, 1, [], ans)
    ans.sort()
    for l in ans:
        for x in l:
            print(x, end=' ')
        print()
