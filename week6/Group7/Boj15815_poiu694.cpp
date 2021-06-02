#include <iostream>
#include <stack>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int calculate(char op, int a, int b)
{
    switch (op)
    {
    case '+':
        return b + a;
    case '-':
        return b - a;
    case '*':
        return b * a;
    case '/':
        return b / a;
    }
}

void solve()
{
    string str;
    cin >> str;

    stack<int> st;
    for (int i = 0; i < str.length(); i++)
    {
        if ('0' <= str[i] && str[i] <= '9')
        {
            st.push(str[i] - '0');
        }
        else
        {
            int temp1 = st.top();
            st.pop();
            int temp2 = st.top();
            st.pop();

            st.push(calculate(str[i], temp1, temp2));
        }
    }

    cout << st.top();
}

int main()
{
    fastIO();
    solve();
}