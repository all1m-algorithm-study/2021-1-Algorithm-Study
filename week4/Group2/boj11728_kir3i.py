import sys
input = sys.stdin.readline

def solv(A, B, N, M):
    ans = []
    aidx, bidx = 0, 0
    while aidx < N and bidx < M:
        if A[aidx] <= B[bidx]:
            ans.append(A[aidx])
            aidx += 1
        else:
            ans.append(B[bidx])
            bidx += 1
    if aidx < N:
        ans.extend(A[aidx:])
    elif bidx < M:
        ans.extend(B[bidx:])

    return ans

if __name__ == '__main__':
    N, M = map(int, input().strip().split())
    A = list(map(int, input().strip().split()))
    B = list(map(int, input().strip().split()))

    print(*solv(A, B, N, M))
