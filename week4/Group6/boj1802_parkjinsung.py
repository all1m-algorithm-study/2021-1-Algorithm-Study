def check_dongho(case, length):
    if length == 1:
        return "YES"
    
    if length == 3:
        if case[0] == case[2]:
            return "NO"
        elif case[0] != case[2]:
            return "YES"
            
    else:
        flag = True
        temp1 = case[:int((length)/2)]
        temp2 = case[int((length+1)/2):]
        temp2 = temp2[::-1]
        for i in range(len(temp1)):
            if temp1[i] == temp2[i]:
                flag = False
                break
        if flag == True:
            return check_dongho(temp1, len(temp1))
        elif flag == False:
            return "NO"

n = int(input())
for i in range(n):
    case = input()
    print(check_dongho(case, len(case)))
