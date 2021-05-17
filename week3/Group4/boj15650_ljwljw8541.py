def com(n,m,start,selected):
    if len(selected) == m:
        print(*selected)
    elif start <= n:
        selected.append(start)
        com(n,m,start+1,selected)
        selected.pop()
        com(n,m,start+1,selected)
N,M = map(int, input().split())
com(N,M,1,[])
