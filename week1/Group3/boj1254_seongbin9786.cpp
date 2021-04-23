#include <stdio.h>
#include "../include/debugopen.hpp"

/*
	[Silver 1]
	팰린드롬 만들기

	주어진 입력에 append 했을 때, 팰린드롬이 되는 최소값?

	abab => 5

	1. palindrome check는 stack에 절반 넣고 빼면서 보면 되는건데

	2. 일단 절반 넣고, 그 다음 원소를 보는거야. 그 그 다음 원소와 같으면, 아 이게 아니지?
	[ex] 가나다다나가
	음, 이미 팰린드롬이면 안 될 거 같지?
	aba + ba (딱히 문제 없네요 ^^)

	----
	팰린드롬이랑은 상관 아예 없다고 가정하고 풀이를 해보자 (물론 논리적으로 틀렸지만 문제 없을 것 같음)

	=> aba 에서 시작한다고 가정하자.
	=> a,b 중에서 랜덤 append를 해볼까?
	=> 재귀로 해봐야 하나? 모든 case를 해봐야 하니까?
	=> 아 나 알았어

	append from the first ?
	가나다
	가나다가나다 failed fucked up
	가나가 (v)
	가나가나 (x)
	가나나가 (v)

	가나가 => palin
	=> if it's palin already then just append chars in a reversed order
	=> should append at least two chars from the beginning
	=> '가나'가 => 가나가 => 가나가'나가' (reversed the first two)
	=> 이런식으로 계속 reverse the first N characters (N=2,......natural number)

	가나 => not palin
	=> first char부터 reversed order로 추가하면 될 것 같다.

	(ex) 
	가라도바로바 => 가라도바로바'도라가' // oh it works somehow!

	-----
	[IDEA]
	1. Check whether it is Palindrom (Nope)
	=> 어차피, 팰린도 똑같이 reversed order로 추가한다.

	2. Buffer에다가, char 1개 추가하고, palin check 하는 식으로 수행
	=> appended chars length = [1...bufferLen];

	3. 팰린드롬 체크 function이 있어야 한다.

	----
	제출
	1. appended만 냈음 (전체 길이를 제공해야 하므로 틀림)
	2. len + appended 냈음 (아, 0개 이상의 문자 추가 였음; )
	3. 성공
	
*/
bool isPalindrome(char *buf, int len)
{
    // 어차피 len는 정수 나눗셈 하면, 홀수이든 짝수이든 한쪽만 남게 된다.
    int i;
    for (i = 0; i < len / 2; i++)
        if (buf[i] != buf[len - 1 - i]) // [0,2], [1,1] 아 되네 굳
            return false;
    return true;
}

int main()
{
    int i, j, len = 0, appended = 1;
    char buf[2000] = {0}; // 모두 null 문자로 시작 (그러면 for 문 돌 때 굳이 null 문자 매번 끝에 할당할 필요 없음)
    READ_TXT("./input.txt", "rt", stdin);
    scanf("%s", buf);
    while (buf[len] != 0)
        len++;
    if (isPalindrome(buf, len))
    {
        printf("%d\n", len);
        return 0;
    }
    // 시간 초과는 나중에 생각해보자 ^.^
    for (i = 0; i < len; i++)
    {
        for (j = 0; j <= i; j++)       // i=0,j=0일 때도 실행돼야 함
            buf[len + j] = buf[i - j]; // 반대로 넣기. j 루프돌 때마다 매번 덮어쓰기 수행
        if (isPalindrome(buf, len + i + 1))
            break;
        appended++;
    }
    printf("%d\n", len + appended);
    return 0;
}