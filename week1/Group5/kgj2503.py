questions=int(input()) //질문 횟수
numbers=list() //질문한 숫자
strikes=list() //스트라이크 수
balls=list() //ball 수
count=0 //가능성이 있는 수 카운팅

def checking(a,b,c,n): //질문으로 들어온 수들과 i번째 수를 비교해서 맞으면 1 틀리면 0 반환하는 함수
    s=0
    ba=0
    flag=0
    three=numbers[n]%10
    two=(numbers[n]//10)%10
    one=(numbers[n]//10)//10
    if a==one:
        s=s+1
    if b==two:
        s=s+1
    if c==three:
        s=s+1
    if a==two:
        ba=ba+1
    if a==three:
        ba=ba+1
    if b==one:
        ba=ba+1
    if b==three:
        ba=ba+1
    if c==one:
        ba=ba+1
    if c==two:
        ba=ba+1
    if s==strikes[n] and ba==balls[n]:
        flag=1
    return flag


for i in range(0,questions):       //입력에 대해 숫자, 스트라이크, 볼로 나누어 저장
    a,b,c=map(int,input().split())
    numbers.append(int(a))
    strikes.append(int(b))
    balls.append(int(c))

for i in range(123,988): // 모든 가능성있는 수들에 대해서 조건에 위배되는 경우를 제외하고 체킹해서 카운팅
    sum=0
    third=i%10
    second=(i//10)%10
    first=(i//10)//10
    if first==second or first==third or second==third or first*second*third==0:
        continue
    for j in range(0,questions):
        sum=sum+checking(first,second,third,j)
    if sum==questions:
        count=count+1

print(count)
    
