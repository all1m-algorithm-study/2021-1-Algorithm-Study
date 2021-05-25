def fold(s):
    n = len(s)
    if(n == 1): return True
    
    for i in range(0, n // 2):
        if(s[i] == s[n - i - 1]):
            return False

    if(fold(s[:n // 2]) and fold(s[n // 2 + 1:])):
        return True
    
    return False

t = int(input())

for i in range(0, t):
    s = input()
    if(fold(s)):
        print('YES')
    else:
        print('NO')
