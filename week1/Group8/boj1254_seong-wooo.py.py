#팰린드롬 만들기
#성공

# 기존의 리스트를 뒤집는다
# 겹치는 부분을 확인한다
# 겹치는 부분이 빼고 나머지의 개수만 더해주면 됨
# abab -> baba  에서 bab 겹치므로 마지막 a 만 더해주면 됨


input_str = input("")
palindrom_str = ''.join(reversed(input_str))

j = 0
for i in range(len(input_str)):
    if input_str[i:] == palindrom_str[:len(input_str) - i]:
        j = i
        break

print(len(input_str) + j)

