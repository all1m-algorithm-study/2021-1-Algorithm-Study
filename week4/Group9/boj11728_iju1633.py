n, m = map(int, input().split())
ab = []
for i in range(2):
    ab += list(map(int, input().split()))
ab.sort()
print(*ab) # 출력 양식이 공백을 두고 하나씩 출력됨