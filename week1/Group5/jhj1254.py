'''
not yet solved
가운데부터 시작
가운데부터 ~ 끝까지 idx 기준으로 반대편이 같은지 체크
다른 문자 나오면 idx 오른쪽으로 한칸 옮기고 이하 반복
끝까지 검사 통과하면 맨 앞에서부터 len(word) + idx - (idx~end)) 반환
abba
0123
aba
012
aabccbad
01234567


'''

def make_palindrome():

    s = input()
    idxmax = len(s) - 1

    pivot = (idxmax + 1)//2

    while pivot < idxmax:
        continue_sign = 0
        for i in range(idxmax - pivot):
            print("idxmax-pivot = {}".format(idxmax - pivot))
            idx = pivot + i
            print("idx = {}".format(idx) + " " + s[idx])
            oppsite_idx = idxmax - idx
            print("oppsite_idx = {}".format(oppsite_idx))
            if s[idx] != s[oppsite_idx]:
                continue_sign = 1
                break
        print("continue_sign = {}".format(continue_sign))
        if continue_sign:
            pivot += 1
            continue
        else:
            return (idxmax + 1) + (pivot - (idxmax - pivot))

    return idxmax*2 + 1

print(make_palindrome())