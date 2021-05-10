N = int(input())
meeting = []
for i in range(N):
    s, e = map(int, input().split())
    meeting.append([s, e])

meeting.sort(key=lambda x: (x[1], x[0]))
count = 0
endtime = 0

for i in range(len(meeting)):
    if endtime <= meeting[i][0]:
        endtime = meeting[i][1]
        count += 1

print(count)