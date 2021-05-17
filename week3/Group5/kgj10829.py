def Int_to_Binary(number):
    if number<2:
        print(number,end='')
        return
    else:
        Int_to_Binary(number//2)
        print(number%2,end='')
    
A=int(input())
Int_to_Binary(A)