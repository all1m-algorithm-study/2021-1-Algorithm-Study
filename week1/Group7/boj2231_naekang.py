# n값을 문자열의 형태로 입력 받기
n = input()

# 생성자 값들이 들어갈 수 있는 배열 생성
new_list = []

# 1부터 n까지 돌며 n과 같아지는 경우 new_list에 추가
# i + sum(int, str(i)) => i 하나씩 돌며 int로 만들고 각 자리수의 합 구하기
for i in range(1, int(n)+1):
    if int(n) == i + sum(map(int, str(i))):
        new_list.append(i)

# 생성자가 없는 경우 0 출력
# 생성자가 있는 경우 min 함수를 이용해 최소값 출력
if len(new_list) == 0:
    print(0)
else:
    print(int(min(new_list)))
