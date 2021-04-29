#include <iostream>
#include <math.h>

/*
    [Silver 3]
    칸토어 집합

    칸토어 집합은 0과 1사이의 실수로 이루어진 집합으로, 
    구간 [0, 1]에서 시작해서 각 구간을 3등분하여 가운데 
    구간을 반복적으로 제외하는 방식으로 만든다.

    집합이 유한
    칸토어 집합의 근사

----
    걍 - 패턴 구하는 재귀 문제이다.
    제거되는 형태가 이진 탐색 (중간은 제거되니깐 삼진 탐색은 아니다.)
----
    1. -가 3N개 있는 문자열에서 시작한다. (중간값이 없을 일이 없다.)

    2. 문자열을 3등분 한 뒤, 가운데 문자열을 공백으로 바꾼다.
     이렇게 하면, 선(문자열) 2개가 남는다.

    3. 이제 각 선(문자열)을 3등분 하고, 가운데 문자열을 공백으로 바꾼다. 
    이 과정은 모든 선의 길이가 1일때 까지 계속 한다.

    예를 들어, N=3인 경우, 길이가 27인 문자열로 시작한다.
----
EXAMPLE

    NUM=3
    N=27
    ===>1/3을 1/3시점부터 제거한다.
    ===>27/3=9 => idx=9면, no no
    ===> idx=8[9번째니까]부터9개 제거
    ===> 이후 idx=0, idx=17 부터 시작 (ok)

    근데 이거 애초에
    buf 만들고 지우고 이러지 말고

    끝까지 간 다음 출력만 하면 되는 것 아닌가?
    
----
틀린 이유:
입력을 여러 줄로 이루어져 있다. 각 줄에 N이 주어진다. 파일의 끝에서 입력을 멈춘다. N은 0보다 크거나 같고, 12보다 작거나 같은 정수이다.

입력이 여러 개였음;;
*/
using namespace std;

int N;

void c(int begin, int end, int depth, bool fill)
{
    if (depth == 0)
    {
        while (begin++ < end)
            cout << (fill ? '-' : ' '); // 괄호 안 치면 111 로 나오는건 뭐야?
        return;
    }
    int tmp = (end - begin) / 3;
    c(begin, begin + tmp, depth - 1, true);
    c(begin + tmp, begin + tmp * 2, 0, false); // depth=0으로 바로 줘야 함. 더 깊이 안들어가니까
    c(begin + tmp * 2, begin + tmp * 3, depth - 1, true);
}

// 입력 받을 개수를 안 주면 어떻게 함?
// 신기한 거 많네 ㅋㅋ
// 이런식으로 푸는 문제도 있구만
int main()
{
    int NUM;

    while (true)
    {
        // cin으로 입력받은 값이 없으면
        // cin.eof()는 true를 반환한다. 당연히 그렇지 않으면 false 반환
        cin >> N;
        if (cin.eof() == true)
            break;
        NUM = (int)pow(3, N);
        c(0, NUM, N, true);
        cout << "\n";
    }
    return 0;
}
