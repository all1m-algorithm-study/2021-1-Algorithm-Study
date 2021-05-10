# 분해합
# 성공
# 자연수에서 생성자를 뺀다.
# 각 자릿수를 뺀 값이 0일 때 가장 작은 값을 찾는다


N = input("")
for i in range(int(N)):
    n = int(N)
    temp = i
    remainder = n - i
    length = len(str(temp))
    for j in range(length):
        remainder -= temp % 10
        temp = int(temp / 10)
    if remainder == 0:
        break
if remainder == 0:
    print(i)
else:
    print(0)