# 하다하다 모르겠어서 구글링 한 코드입니다
s=input()

for i in range(len(s)):
    if s[i:] == s[i:][::-1]:
        print(len(s)+i)
        break

# 아래 제가 짠 코드로 하니까 메모리 초과 나서 결국 구글링 한 위에 코드를 사용 했습니다.. ㅠ
# def checkPal(string):
#     for i in range(len(string)):
#         if len(string)%2 == 0 and i == len(string)/2:
#             return True
#         if len(string)%2 == 1 and i >= (len(string) - 1)/2:
#             return True
#         if string[i] != string[len(string) - 1 - i]:
#             return False

# s = input()
# sLst = list(set(s))
# maxAddLength = len(s) - 1
# palLst = []
# palLst.append(s)
# tempLst = []
# flag = True
# mainFlag = True
# if maxAddLength == 0:
#     print(1)
#     mainFlag = False
# if checkPal(s):
#     print(len(s))
#     mainFlag = False

# if mainFlag:
#     for k in range(maxAddLength):
#         for i in palLst:
#             for j in sLst:
#                 tempLst.append(i+j)
#                 if checkPal(i+j):
#                     print(len(i+j))
#                     flag = False
#                     break
#             if flag == False:
#                 break
#         if flag == False:
#             break
#         palLst = tempLst
#         tempLst = []

