#include <iostream>

/*
    [Silver 1]
    곱셈 (거듭제곱 구하기)
    왜 틀렸는지 모르겠음
*/
using namespace std;

int a, c;

long long mul(int b)
{
    if (b == 0)
        return 1;
    long long t = mul(b / 2);
    t = (t * t) % c;
    if (b % 2 == 1)
        return (a * t) % c;
    return t;
}

int main()
{
    int b;
    cin >> a >> b >> c;
    cout << mul(b) << "\n";
    return 0;
}
