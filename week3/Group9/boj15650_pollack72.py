# example
N, M = map(int, input().split())

def comb(N, M, start, selected):
    if len(selected) == M:
        print(*selected)
    elif start <= N:
        selected.append(start)
        comb(N, M, start+1, selected)
        selected.pop()
        comb(N, M, start+1, selected)

comb(N, M, 1, [])