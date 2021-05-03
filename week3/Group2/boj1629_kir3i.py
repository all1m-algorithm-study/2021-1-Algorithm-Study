import sys
input = sys.stdin.readline

def solv(A, B, C):
    if B <= 2:
        return (A**B) % C

    if B %2 == 1:
        return ((solv(A, B // 2, C) % C) ** 2) * A
    else:
        return (solv(A, B // 2, C) % C) ** 2

if __name__ == '__main__':
    A, B, C = map(int, input().strip().split())
    print(solv(A, B, C) % C)
