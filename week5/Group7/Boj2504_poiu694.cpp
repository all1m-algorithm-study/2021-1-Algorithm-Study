#include <iostream>
#include <stack>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    string str;
    cin >> str;

    stack<char> st;
    stack<int> answer;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '[') // 열린괄호는 answer - 0 , st - ( || [
        {
            st.push(str[i]);
            answer.push(0);
        }
        else if (str[i] == ')')
        {
            if (st.empty() || st.top() != '(') // (가 없으면 짝이 안맞는 경우
            {
                cout << '0';
                return;
            }

            int num = 0;
            while (answer.top() != 0 && !answer.empty())
            { // 0이 아니기 전까지는 다 더해줄 것들
                num += answer.top();
                answer.pop();
            }
            // 0이 나오면 Nesting 되어있던 것들
            if (!st.empty())
            {
                if (st.top() == '(')
                { // 0이 나왔을 경우에 Nesting 되어있던 것들
                    num *= 2;
                    num = num == 0 ? 2 : num; // 0이 나왔을 경우
                }
                else if (st.top() == '[')
                {
                    num *= 3;
                    num = num == 0 ? 3 : num; // 0이 나왔을 경우
                }
                st.pop();
                answer.pop(); // 0이랑 기존 괄호 제거
            }

            answer.push(num);
        }
        else if (str[i] == ']')
        {
            if (st.empty() || st.top() != '[') // 종료조건
            {
                cout << '0';
                return;
            }
            int num = 0;
            while (answer.top() != 0 && !answer.empty())
            { // 0이 아니기 전까지는 다 더해줄 것들
                num += answer.top();
                answer.pop();
            }
            // 0이 나오면 Nesting 되어있던 것들
            if (!st.empty())
            {
                if (st.top() == '(')
                { // 0이 나왔을 경우에 Nesting 되어있던 것들
                    num *= 2;
                    num = num == 0 ? 2 : num; // 0이 나왔을 경우
                }
                else if (st.top() == '[')
                {
                    num *= 3;
                    num = num == 0 ? 3 : num; // 0이 나왔을 경우
                }
                st.pop();
                answer.pop(); // 0이랑 기존 괄호 제거
            }

            answer.push(num);
        }
    }

    // 괄호가 짝이 안맞는 경우 (()()[]
    if (!st.empty())
    {
        cout << '0';
        return;
    }

    int sum = 0;
    while (!answer.empty())
    {
        sum += answer.top();
        answer.pop();
    }
    cout << sum;
}

int main()
{
    fastIO();
    solve();
}