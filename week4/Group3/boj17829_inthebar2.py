# dac(matrix, (0, 2), (0, 2))
def dac(matrix, row, col):
	# print(row, col)
	res = []
	if row[1] - row[0] == 2 and col[1] - col[0] == 2:
		res.append(matrix[row[0]][col[0]])
		res.append(matrix[row[0]][col[1] - 1])
		res.append(matrix[row[1] - 1][col[0]])
		res.append(matrix[row[1] - 1][col[1] - 1])
		res.sort()
		return res[-2]
	
	mid_row = (row[0] + row[1]) // 2
	mid_col = (col[0] + col[1]) // 2
	res.append(dac(matrix, (row[0], mid_row), (col[0], mid_col)))
	res.append(dac(matrix, (row[0], mid_row), (mid_col, col[1])))
	res.append(dac(matrix, (mid_row, row[1]), (col[0], mid_col)))
	res.append(dac(matrix, (mid_row, row[1]), (mid_col, col[1])))
	
	res.sort()
	return res[-2]

N = int(input(''))
matrix = []

for i in range(N):
	matrix.append(list(map(int, input().split(' '))))

print(dac(matrix, (0, N), (0, N)))