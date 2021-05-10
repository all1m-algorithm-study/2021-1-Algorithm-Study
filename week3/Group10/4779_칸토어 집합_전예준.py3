import itertools
while 1:
    p=input()
    if p=='0':
        break
    _,*u=list(map(int,p.split()))
    for i in itertools.combinations(u,6):
        print(*i)
    print()