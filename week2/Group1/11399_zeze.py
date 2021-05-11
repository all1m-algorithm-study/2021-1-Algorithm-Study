num = int(input())

using_atm_time = list(map(int, input().split()))
using_atm_time.sort() # 대기시간을 줄이기 위해 사용 시간이 짧은 사람부터 먼저 이용하기

now_time = 0
wating_time_sum = 0

for i in range(num):
    now_time += using_atm_time[i] + wating_time_sum
    wating_time_sum += using_atm_time[i]

print(now_time)
