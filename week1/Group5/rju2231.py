n = int(input())
i = len(str(n))

m = n - 9 * i
if(m < 0): m += 9

while(True):
	s = m + sum(map(int, str(m)))

	if(n < m):
		print(0)
		break
	if(n == s):
		print(m)
		break

	m += 1