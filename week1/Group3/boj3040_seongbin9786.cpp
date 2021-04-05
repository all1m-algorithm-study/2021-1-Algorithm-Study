#include <iostream>
#include <algorithm>
#include "../include/debugopen.hpp"

/*
	[Bronze 2]
	백설 공주와 일곱 난쟁이

	1. 7명의 난쟁이의 숫자의 합은 100이다.

	2. 현재 엔트리는 9명이다.

	3. 7명이 되는 세트를 찾아라.

	4. 답은 유일하다.

	----
	[IDEA]
	1. 9개 숫자를 전부 더한다
	2. sum - 100과 일치하는 두 개의 조합을 찾는다.
*/

using namespace std;

int main()
{
    int i, j, sum = 0, diff, tmp = 0;
    int buffer[9];
    READ_TXT("./input.txt", "rt", stdin);
    for (i = 0; i < 9; i++)
    {
        cin >> buffer[i];
        sum += buffer[i];
    }
    diff = sum - 100;
    //printf("diff = %d\n", diff);
    for (i = 0; i < 9; i++)
        for (j = 0; j < 9; j++)
        {
            if (i == j)
                continue;
            tmp = buffer[i] + buffer[j];
            //printf("tmp = %d\n", tmp);
            if (tmp == diff)
            {
                buffer[i] = 0;
                buffer[j] = 0;
                //printf("It is buffer[%d] = %d, buffer[%d] = %d\n", i, buffer[i], j, buffer[j]);
                goto DONE;
            }
        }
DONE:
    sort(buffer, buffer + 9);
    for (i = 2; i < 9; i++)
        cout << buffer[i] << "\n";
    return 0;
}
