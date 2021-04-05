#include <iostream>

/*
	[Bronze 2]
	분해합
	N = 245 = (245 + 2 + 4 + 5 = 256)
	M = 256

	N은 M의 생성자

	임의의 M에 대해, 가장 작은 생성자를 찾자.

	어떤 자연수는 생성자가 없을 수 있고, 어떤 자연수는 생성자가 여러 개일 수 있다.
	
	---
	생성자를 찾는 것은 간단하다.
	N + N1 + N2 + .. + Nk = M인 N의 min을 계속 갱신하면 된다.

*/
using namespace std;

int main()
{
    int N;
    int i, j, tmp, sum, min;
    cin >> N;
    min = N; // 그냥 임의의 max 값
    for (i = 1; i <= N; i++)
    {
        sum = i;
        tmp = i;
        while (tmp > 0)
        {
            sum += tmp % 10;
            tmp /= 10;
        }
        if (sum == N && i < min)
            min = i;
    }
    if (min == N)
        min = 0;
    cout << min << "\n";
    return 0;
}
