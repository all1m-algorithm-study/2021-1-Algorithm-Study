# 출력: 단어의 합의 최댓값

# 체크할 조건
# 1 <= N <= 10 (단어의 개수)
    # 자리수가 클수록 장땡

# 자리수가 가장 높은 알파벳에 가장 높은 숫자
    # 같은 게 여러 개 있으면 더 많이 나타나는것
        # 그 다음 높은 자리수 가지는 알파벳

N = int(input())
lst = []
maxl = 0
for n in range(N):
    temp = input()
    lst.append(temp)
    maxl = max(len(temp), maxl)
lst.sort(key=lambda x: len(x), reverse=True)

order = dict()
mul = 10 ** (maxl-1)
for i in range(-maxl,0):
    for char in lst:
        try:
            if order.get(char[i]):
                order[char[i]] += 1 * mul
            else:
                order[char[i]] = 1 * mul
        except:
            pass
    else:
        mul //= 10

orderlist = list(order.items())
orderlist.sort(key=lambda x: x[1], reverse=True)
resultdict = dict()
idx = 9
for letter, val in orderlist:
    resultdict[letter] = idx
    idx -= 1

result = 0
for word in lst:
    temp = 0
    for letter in word:
        temp *= 10
        temp += resultdict.get(letter)
    result += temp

print(result)