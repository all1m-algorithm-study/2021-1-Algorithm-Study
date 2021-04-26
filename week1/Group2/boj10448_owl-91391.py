def preCalculate() :
    n=1
    for i in range(1,50) :
        a=i*(i+1)/2
        if a <=1000 :
            eureka.append(int(a))
        else :
            break



num = int(input())
data = [int(input()) for i in range(num)]
eureka=[]
preCalculate()
length = len(eureka)
sum_value=0
for s in range(num) :
    num_break=0
    for i in range(length) :
        for j in range(length) :
            for k in range(length) :
                sum_value=eureka[i] + eureka[j] + eureka[k]
                if sum_value == data[s] :
                    print(1)
                    num_break = 1
            if num_break ==1 :
                break
        if num_break ==1 :
            break
    if num_break ==0 :
        print(0)