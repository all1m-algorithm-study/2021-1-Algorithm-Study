# 1. 입력한 문자열을 반전한 문자열을 뒤에 추가한 후 펠린드롬인지 확인
# 2. 펠린드롬이면 길이 저장, 이후 반전한 문자열에서 가장 앞에 있는 문자 1개 삭제 후 재비교
#
# 시간복잡도 = O(n^2)

def isPelindrome(str):
    length = len(str)
    for i in range(int(length / 2)):
        if str[i] != str[length - i - 1]:
            return False
    return True


str = input()
revStr = str[::-1]


for i in range(len(revStr) + 1):
    checkStr = str + revStr
    if isPelindrome(checkStr):
        minLength = len(checkStr)
    revStr = revStr[1:]

print(minLength)
