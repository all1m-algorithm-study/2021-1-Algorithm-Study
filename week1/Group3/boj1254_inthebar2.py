def is_palindrome(s):
    i = 0
    j = len(s) - 1
    while i < j:
        if s[i] != s[j]:
            return False
        i += 1
        j -= 1
    return True

s = input()

if is_palindrome(s):
    print(len(s))
else:
    r = s[::-1]

    for i in range(len(s) - 1, 0, -1):
        # print(s + r[i:])
        if is_palindrome(s + r[i:]):
            print(len(s + r[i:]))
            break
