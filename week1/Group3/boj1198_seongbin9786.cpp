#include <iostream>
#include <vector>
#include <iomanip>

#include "../include/debugopen.hpp"

/*
	[Silver 3]
	삼각형으로 자르기
	
	볼록 다각형이 있고, 3개의 <<연속된>> 점을 선택해서 삼각형을 만든다. 
	그 다음이 만든 삼각형을 다각형에서 제외한다. 
	원래 다각형이 N개의 점이 있었다면, 이제 N-1개의 점으로 구성된 볼록 다각형이 된다.

	위의 과정은 남은 다각형이 삼각형이 될 때까지 반복한다.

	볼록 다각형의 점이 시계 방향순으로 주어진다. 
	마지막에 남은 삼각형은 여러 가지가 있을 수 있다. 
	이 때, 가능한 넓이의 최댓값을 구하는 프로그램을 작성하시오.

    ---
    참고 자료:
    1. 블록 다각형: https://ko.wikipedia.org/wiki/%EB%8B%A4%EA%B0%81%ED%98%95#/media/%ED%8C%8C%EC%9D%BC:Polygon_venn_diagram.svg
    2. 사선 공식: https://medium.com/@joongi1978/algorithm-3-%EC%84%B8-%EC%A0%90%EC%9D%84-%EC%95%8C-%EB%95%8C-%EC%82%BC%EA%B0%81%ED%98%95%EC%9D%98-%EB%84%93%EC%9D%B4%EB%A5%BC-%EA%B5%AC%ED%95%98%EB%8A%94-%EB%B0%A9%EB%B2%95-%EC%82%AC%EC%84%A0-%EC%8B%A0%EB%B0%9C%EB%81%88-%EA%B3%B5%EC%8B%9D-232ed0dc94d8
    3. setprecision: https://medium.com/@peteryun/algo-%EC%B2%98%EC%9D%8C%ED%95%98%EB%8A%94-c-%EA%B8%B0%EB%B3%B8%EC%9E%85%EC%B6%9C%EB%A0%A5-setprecision-2a42d7df1235
    
	---
	[IDEA]
	1. 점을 3개씩 선택해서 넓이를 구해 MAX 값을 구하면 될 일이다.
	2. 점을 3개 골라야 하므로 삼중 포문을 사용한다.

	---
	상대 오차에 대해:
	- 말 그대로 오차 10^(-9) 이하여야 한다는 뜻
	- 그렇다는건 0.000000001 이하
	- 적어도 소수점 10자리는 출력해줘야 한다.
*/

using namespace std;

int main()
{
    int N, i, j, k, x, y;
    pair<int, int> a, b, c;
    double first, second, sum, max;
    READ_TXT("./input.txt", "rt", stdin);
    cin >> N;
    pair<int, int> arr[N];
    for (i = 0; i < N; i++)
    {
        cin >> x >> y;
        arr[i] = make_pair(x, y);
    }

    // 넓이 구하기 (사선 공식)
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            if (i == j)
                continue;
            for (k = 0; k < N; k++)
            {
                if (i == k || j == k)
                    continue;
                a = arr[i];
                b = arr[j];
                c = arr[k];
                first = (a.first * b.second) + (b.first * c.second) + (c.first * a.second);
                second = (a.second * b.first) + (b.second * c.first) + (c.second * a.first);
                sum = (first - second) / 2;
                if (sum < 0)
                    sum *= -1;
                if (max < sum)
                    max = sum;
            }
        }
    cout << setprecision(10) << max << "\n";
    return 0;
}
