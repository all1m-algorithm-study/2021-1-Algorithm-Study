import sys

def solv(line):
    N = len(line)
    if N == 1:
        return '-'
    pre = solv(line[:N//3])
    return  pre + (' ' * (N//3)) + pre

if __name__ == '__main__':
    for N in sys.stdin:
        N = int(N)
        if N == None:
            break
        print(solv('-' * (3**N)))
