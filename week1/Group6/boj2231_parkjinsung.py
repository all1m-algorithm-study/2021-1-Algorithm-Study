n_string = input()
n = int(n_string)

diNumSum = 0
for m in range((n - len(n_string)*9), n+1):
    if m <= 0:
        continue
    m_string = str(m)
    for diNum in range(len(m_string)):
        diNumSum += int(m_string[diNum])
    if (m + diNumSum) == n:
        print(m)
        flag = False
        exit(0)
    diNumSum = 0
print(0)
