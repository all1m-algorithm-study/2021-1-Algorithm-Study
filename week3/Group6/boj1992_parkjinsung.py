def check_pixel(pixel, n):
    check = pixel[0][0]
    temp = -1
    for i in range(n):
        for j in range(n):
            temp = pixel[i][j]
            if temp != check:
                return -1
    return check

def slice_pixel(pixel, n, r, c):
    sliced_num = int(n/2)
    sliced_pixel = []
    for i in range(r*sliced_num, r*sliced_num + sliced_num):
        temp = ""
        for j in range(c*sliced_num, c*sliced_num + sliced_num):
            temp += pixel[i][j]
        sliced_pixel.append(temp)
        temp = ""
    return sliced_pixel


ans = ""
def zip_pixel(pixel, n):
    global ans
    if check_pixel(pixel, n) == '0':
        ans += "0"
    elif check_pixel(pixel, n) == "1":
        ans += "1"
    elif check_pixel(pixel, n) == -1:
        ans += "("
        for i in range(2):
            for j in range(2):
                zip_pixel(slice_pixel(pixel, n, i, j), int(n/2))
        ans += ")"

n = int(input())
pixel = []
for i in range(n):
    sliced_pixel = input()
    pixel.append(sliced_pixel)

zip_pixel(pixel, n)
    
print(ans)
