def how(n, guess):
    n = str(n)
    guess = str(guess)
    
    strike = 0
    ball = 0
    for i in range(0, 3):
        if n[i] == guess[i]:
            strike += 1
        else:
            if n[i] in guess:
                ball += 1
    return (strike, ball)

N = int(input())
guesses = list()

for _ in range(N):
    guesses.append(input())

res = [1 for _ in range(1000)]

for n in range(111, 1000): # 0이 들어간 것들이나 중복되는 것들 삭제...
    str_n = str(n)
    if '0' in str_n or str_n[0] == str_n[1] or str_n[1] == str_n[2] or str_n[0] == str_n[2]:
        res[n] = 0

for n in range(111, 1000): 
    if res[n]:
        for guess in guesses:
            num = guess[:4]
            strike = int(guess[4])
            ball = int(guess[6])
            if how(str(n), num) != (strike, ball):
                res[n] = 0
                break

cnt = 0
for n in range(111, 1000):
    if res[n]:
        # print(n)
        cnt += 1

print(cnt)
