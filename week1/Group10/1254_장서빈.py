def palindrome(s):
    qu = [] # 큐
    st = [] # 스택
    
    for x in s:
        if x.isalpha(): # 해당 문자가 공백, 숫자, 특수문자가 아니면
            qu.append(x.lower())
            st.append(x.lower())
        
    while qu: # 큐에 문자가 남아있는 한
        if qu.pop(0) != st.pop(): #큐와 스택에 문자를 하나씩 꺼내면서 비교
            return False
    
    return True

word = list(input())

x = 0

for i in range(1,len(word)):
    if palindrome(word[len(word)-i:len(word)]):
        x = i
if palindrome(word):
    print(len(word))
else:
    print(2*len(word) - x)