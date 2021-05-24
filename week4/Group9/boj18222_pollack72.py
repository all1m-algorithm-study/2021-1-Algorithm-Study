# G - 투에-모스 문자열
k = int(input())

exp = 0
while True:
    if (k-1) >= 2**exp:
        exp += 1
    else:
        exp -= 1
        break

def Thue_Morse(k, reversal, exp):
    if k==0:
        if reversal%2 == 0: return 0
        else: return 1
    else:
        if k // (2**exp) == 1:
            reversal += 1
            exp -= 1
            return Thue_Morse(k % (2**(exp+1)), reversal, exp)
        else:
            exp -= 1
            return Thue_Morse(k, reversal, exp)

print(Thue_Morse(k-1, 0, exp))




