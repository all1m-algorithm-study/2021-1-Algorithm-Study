N=int(input())

def digit_array(number):
    digit=list()
    mock=number
    while mock>0:
        digit.append(mock%10)
        mock=mock//10
    return digit

Is_min=0
min=1000000
for i in range(1,N+1):
    sum_digit=sum(digit_array(i))
    Is_min=i+sum_digit
    if Is_min==N and i<min:
        min=i

if min==1000000:
    min=0

print(min)
