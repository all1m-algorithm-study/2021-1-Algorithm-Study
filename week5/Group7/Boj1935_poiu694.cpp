#include <iostream>
#include <stack>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout.precision(2);
}

double calculate(char op, double a, double b)
{
    double answer = 0;
    switch (op)
    {
    case '+':
        answer = b + a;
        break;
    case '-':
        answer = b - a;
        break;
    case '/':
        answer = b / a;
        break;
    case '*':
        answer = b * a;
        break;
    }

    return answer;
}

void solve()
{
    int alpha[27];
    int N;
    string str;

    cin >> N >> str;

    for (int i = 0; i < N; i++)
    {
        cin >> alpha[i];
    }

    stack<double> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
        {
            double temp1 = st.top();
            st.pop();
            double temp2 = st.top();
            st.pop();

            double sum = calculate(str[i], temp1, temp2);
            st.push(sum);
        }
        else
        {
            st.push(alpha[str[i] - 'A']);
        }
    }

    cout << st.top();
}

int main()
{
    fastIO();
    solve();
}