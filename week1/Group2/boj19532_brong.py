arr = list(map(int,input().split()))
y = (arr[0]*arr[5]-arr[2]*arr[3])//(arr[0]*arr[4]-arr[1]*arr[3])
for x in range(-999,1000):
    if arr[0]*x + arr[1]*y == arr[2] and arr[3]*x+arr[4]*y==arr[5]:
        arr2 = [x,y]
        print(arr2[0],arr2[1])