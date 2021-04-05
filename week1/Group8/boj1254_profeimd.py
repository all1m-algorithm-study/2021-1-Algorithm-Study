s = input()
for i in range (len(s)) :
    s_section = s[i:]
    if s_section == s_section[::-1] :
        print(len(s) + i)
        break