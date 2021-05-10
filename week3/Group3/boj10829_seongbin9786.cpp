#include <iostream>
#include <stack>

/*
근데 이걸 왜 재귀로 풀어야 되는거지?
아 ㅋㅋ 스택 대신 쓰라는거네
나는 귀찮으니 스택 쓴다
*/
using namespace std;

int main()
{
    // 숫자범위가 long long으로 커버됨
    // string으로 받았을 때도 modulo가 가능한가? no..
    stack<int> s;
    uint64_t num;
    cin >> num;
    while (num > 0)
    {
        s.push(num % 2);
        num /= 2;
    }
    while (!s.empty())
    {
        cout << s.top(); // 이거 막 \n 이런 거 없지?
        s.pop();
    }
    cout << "\n"; // '\n'도 되나? 누군 그렇게 하는거 본 적 있는 거 같음..
    return 0;
}