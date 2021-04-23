#include <iostream>

/*
	[Bronze 2]
	수학은 비대면강의입니다

	1. 일차연립방정식 풀기 - 브루트포스 문제
*/

using namespace std;

int main()
{
    int a, b, c, d, e, f;
    int x, y;
    READ_TXT("./input.txt", "rt", stdin);
    cin >> a >> b >> c >> d >> e >> f;
    for (x = -999; x <= 999; x++)
        for (y = -999; y <= 999; y++)
        {
            if (c != a * x + b * y)
                continue;
            if (f != d * x + e * y)
                continue;
            goto DONE;
        }
DONE:
    cout << x << " " << y << "\n";
    return 0;
}
