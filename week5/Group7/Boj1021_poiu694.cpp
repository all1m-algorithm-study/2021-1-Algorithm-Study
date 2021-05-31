#include <iostream>
#include <deque>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void move_left(deque<int> &dq)
{
    int num = dq.front();
    dq.pop_front();
    dq.push_back(num);
}

void move_right(deque<int> &dq)
{
    int num = dq.back();
    dq.pop_back();
    dq.push_front(num);
}

int distL(deque<int> dq, int target)
{
    int cnt = 0;

    while (dq.front() != target)
    {
        move_left(dq);
        cnt++;
    }

    return cnt;
}

int distR(deque<int> dq, int target)
{
    int cnt = 0;

    while (dq.front() != target)
    {
        move_right(dq);
        cnt++;
    }

    return cnt;
}

void solve()
{
    int N, M;
    cin >> N >> M;

    deque<int> dq;
    for (int i = 1; i <= N; i++)
    {
        dq.push_back(i);
    }

    int answer = 0;
    int temp;
    for (int i = 0; i < M; i++)
    {
        cin >> temp;

        int dist_L = distL(dq, temp);
        int dist_R = distR(dq, temp);

        if (dist_L < dist_R)
        {
            answer += dist_L;
            for (int i = 0; i < dist_L; i++)
            {
                move_left(dq);
            }
        }
        else
        {
            answer += dist_R;
            for (int i = 0; i < dist_L; i++)
            {
                move_right(dq);
            }
        }
    }

    cout << answer;
}

int main()
{
    fastIO();
    solve();
}