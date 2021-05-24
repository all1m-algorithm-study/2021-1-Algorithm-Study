#include <stdio.h>
#include <vector>

/*
    [Silver 3]
    색종이 만들기

    전체 종이의 크기가 N×N(N=2k, k는 1 이상 7 이하의 자연수) 이라면 종이를 자르는 규칙은 다음과 같다.

    정사각형 타일로 파란색을 표현하는 최소의 개수를 출력하면 된다.
*/

using namespace std;

template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T, U> &l, const std::pair<T, U> &r)
{
    return {l.first + r.first, l.second + r.second};
}

int N;
int M[128][128]; // 2^7=128

pair<int, int> divide(int x1, int x2, int y1, int y2)
{
    if (x2 - x1 > 1) // 2*2 부터
    {
        int midX = (x2 + x1) / 2;
        int midY = (y2 + y1) / 2;
        pair<int, int> res = make_pair(0, 0);
        res = res + divide(x1, midX, y1, midY);
        res = res + divide(midX, x2, y1, midY);
        res = res + divide(x1, midX, midY, y2);
        res = res + divide(midX, x2, midY, y2);
        if (res.first && !res.second)
            return make_pair(1, 0);
        else if (!res.first && res.second)
            return make_pair(0, 1);
        return res;
    }
    else // merge 단계: 한 칸 case
        return M[x1][y1] ? make_pair(1, 0) : make_pair(0, 1);
}

int main()
{
    // 1. 단순 입력
    int i, j;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            scanf("%d", &M[i][j]);

    // 2. 분할정복
    pair<int, int> result = divide(0, N, 0, N);
    printf("%d\n%d\n", result.second, result.first); // 흰색, 파란색 순서라서 거꾸로 해줘야 함
    return 0;
}
