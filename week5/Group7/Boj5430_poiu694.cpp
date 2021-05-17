#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <stack>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void parseToDeque(deque<int> &dq, string &target, int N)
{
    if (N == 0)
    { // Error Case :
        return;
    }
    stack<int> st;

    for (int i = 1; i < target.length(); i++)
    { // 맨 처음은 '['이라 생략
        if ('0' <= target[i] && target[i] <= '9')
        {
            st.push(target[i] - '0');
        }
        else
        {
            int sum = 0, p = 0;

            while (!st.empty())
            {
                sum += st.top() * pow(10, p);
                st.pop();
                p++;
            }
            dq.push_back(sum);
        }
    }
}

void ACOperator(deque<int> &dq, string &op)
{                      // WORST O(NM) . M : operator's length
    bool flag = false; // isReverse ? true : false
    for (int i = 0; i < op.length(); i++)
    { // O(M)
        switch (op[i])
        {
        case 'R':
            flag = !flag; // 실제로 돌리면 TLE
            break;
        case 'D':
            if (dq.empty())
            { // Error Case : empty Dq & pop
                cout << "error" << '\n';
                return;
            }
            if (flag)
            {
                dq.pop_back();
            }
            else
            {
                dq.pop_front();
            }
            break;
        }
    }

    if (dq.empty())
    { // Error Case :  1 R 0 []
        cout << "[]" << '\n';
        return;
    }

    cout << '[';
    if (flag)
    {
        for (int i = dq.size() - 1; i > 0; i--)
        {
            cout << dq[i] << ',';
        }
        cout << dq[0] << ']' << '\n';
    }
    else
    {
        for (int i = 0; i < dq.size() - 1; i++)
        { // O(N)
            cout << dq[i] << ',';
        }
        cout << dq[dq.size() - 1] << ']' << '\n';
    }
}

void solve()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        string op, str;
        deque<int> dq;
        cin >> op >> N >> str;

        parseToDeque(dq, str, N); // dq에 1,2,3,4 추가
        ACOperator(dq, op);
    }
}

int main()
{
    fastIO();
    solve();
}