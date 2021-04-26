#include <iostream>
#include "../include/debugopen.hpp"

/*
	[Bronze 2]
	블랙잭

	1. N개 카드, 모두 숫자 >= 0, 3개를 골라 M >= SUM인 max SUM을 만들기
	---
	[IDEA]
	카드의 개수가 100개 이하이기 때문에, 계산하는 것보다는 그냥 다 해보는 게 좋겠다.

	---
	1회 실패 : j == k 안 넣음. 바보 인정
	2회 실패 : max=0으로 초기화 안 해서 틀림..ㅋㅋ

*/

using namespace std;

int main()
{
    int N, M;
    int i, j, k, sum, max = 0;
    READ_TXT("./input.txt", "rt", stdin);
    cin >> N >> M;
    int arr[N];
    for (i = 0; i < N; i++)
        cin >> arr[i];

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            if (i == j)
                continue;
            for (k = 0; k < N; k++)
            {
                if (i == k || j == k)
                    continue;
                sum = arr[i] + arr[j] + arr[k];
                if (sum > M)
                    continue;
                if (sum > max)
                    max = sum;
            }
        }
    cout << max << "\n";
    return 0;
}
