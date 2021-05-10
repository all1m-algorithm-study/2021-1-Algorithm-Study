# import sys

# A, B, C = map(int, sys.stdin.readline().split())

# print(pow(A, B, C))

import sys

A, B, C = map(int, sys.stdin.readline().split())


def solve(A, B):
    if B == 1:
        return A % C
    else:
        n = solve(A, B // 2)
        if B % 2 == 0:
            return n * n % C
        else:
            return n * A % C


print(solve(A, B))
