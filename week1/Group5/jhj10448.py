def check_eureka(num, lst_trinum):

    idxmax = len(lst_trinum)

    for a in range(1, idxmax):
        for b in range(a, idxmax):
            for c in range(b, idxmax):
                if lst_trinum[a] + lst_trinum[b] + lst_trinum[c] == num:
                    return 1

    return 0




def check_eurekanum():

    num_cases = int(input())
    cases = []

    lst_trinum = []
    for i in range(45):
        lst_trinum.append(i*(i+1)//2)

    for i in range(num_cases):
        cases.append(int(input()))

    for case in cases:
        print(check_eureka(case, lst_trinum))

    return 0

check_eurekanum()
