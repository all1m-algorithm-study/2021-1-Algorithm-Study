n = int(input())
people = list(map(int, input().split()))
people.sort(reverse=True)

s = 0
for i in range(n):
    s += people[i]*(i+1)

print(s)
