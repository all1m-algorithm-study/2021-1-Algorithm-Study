# 1. 모든 회의실 시간을 정렬한다.
# 2. 가장 마지막 시간의 시작 시간을 탐색 기준으로 설정한 후 탐색을 진행한다.
# 3. 회의 마무리 시간이 탐색 기준과 같거나 작으면 해당 회의 시간의 시작 시간을 탐색 기준으로 설정한다.
#
# 시간복잡도 = O(nlogn)

n = int(input())
meetings = []
for _ in range(n):
    meeting = list(map(int, input().split(" ")))
    meetings.append(meeting)

meetings.sort()

count = 1
standard = meetings[n-1][0]
for i in range(n-2, -1, -1):
    if meetings[i][1] <= standard:
        standard = meetings[i][0]
        count += 1

print(count)