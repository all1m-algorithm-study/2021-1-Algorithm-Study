import sys
input = sys.stdin.readline

def get_bin(N):
    if N == 0 or N == 1:
        return str(N)
    return get_bin(N//2) + str(N%2)

if __name__ == '__main__':
    N = int(input().strip())
    print(get_bin(N))
