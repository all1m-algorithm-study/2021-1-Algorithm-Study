#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve()
{
    int N;
    cin >> N;

    queue<int> now;
    stack<int> wait;
    priority_queue<int> pq;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        now.push(temp);
        pq.push(-temp);
    }

    while (!pq.empty())
    {
        int turnPerson = -pq.top(); // 현재 나갈 차례

        if (!now.empty() && turnPerson == now.front())
        {
            now.pop();
            pq.pop();
        }
        else if (!wait.empty() && turnPerson == wait.top())
        {
            wait.pop();
            pq.pop();
        }
        else if (!now.empty() && turnPerson != now.front())
        {
            int waitPerson = now.front(); // 기다려야 하는 사람
            now.pop();
            wait.push(waitPerson);
        }
        else
        {
            break;
        }
    }

    if (pq.empty())
    {
        cout << "Nice";
    }
    else
    {
        cout << "Sad";
    }
}

int main()
{
    fastIO();
    solve();
}