S = input()

length = len(S)
copyS = S
reverseS = ''.join(reversed(S))
token = ''

for i in range(length):
    if reverseS == copyS:
        break
    else:
        token = copyS[0:1] + token
        copyS = copyS[1:]
        reverseS = reverseS[:-1]

result = S + token
print(len(result))
