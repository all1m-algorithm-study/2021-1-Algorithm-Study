#include <iostream>
#include <vector>
#include "../include/debugopen.hpp"

/*
	[Bronze 2]
	유레카 이론
	
	삼각수 = 1, 3, 6, 10, 과 같이 Ek = (1+...+k)

	M이 정확히 3개의 삼각수로 표현되는가? (M <= 1,000 이고 T는 ? )

	---
	[IDEA]
	1. 일단 삼각수를 필요한만큼 다 구해놓는다.
	2. 삼각수를 3중 포문으로 조합한다. (중복 가능)
*/

using namespace std;

int main()
{
    int N, M;
    int i, j, k, m, sum, tmp, len = 0;
    READ_TXT("./input.txt", "rt", stdin);
    cin >> N;
    int three[1000] = {0};
    three[len++] = 1;

    for (i = 0; i < N; i++)
    {
        cin >> M;
        // 삼각수 세팅
        while (three[len - 1] < M)
        {
            three[len] = three[len - 1] + len + 1;
            len++;
        }

        sum = 0;
        for (j = 0; j < len; j++)
            for (k = 0; k < len; k++)
                for (m = 0; m < len; m++)
                {
                    if (three[j] + three[k] + three[m] == M)
                    {
                        cout << "1";
                        goto NEXT;
                    }
                }
        cout << "0";
    NEXT:
        cout << "\n";
    }
    return 0;
}
