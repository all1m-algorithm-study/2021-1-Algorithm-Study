#include <iostream>
#include <vector>
#include <algorithm>
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
    int A, B, C;
    cin >> A >> B >> C;

    vector<int> list;

    bool visited[201][201][201] = {
        false,
    };
    queue<pair<int, pair<int, int> > > q;
    q.push({0, {0, C}});

    while (!q.empty())
    {
        int nowA = q.front().first;
        int nowB = q.front().second.first;
        int nowC = q.front().second.second;
        q.pop();

        if (visited[nowA][nowB][nowC])
            continue;

        visited[nowA][nowB][nowC] = true;

        if (nowA == 0)
        {
            list.push_back(nowC);
        }

        // A -> B / C
        if (nowA + nowB > B)
        {
            q.push({nowA - (B - nowB), {B, nowC}});
        }
        else
        {
            q.push({0, {nowA + nowB, nowC}});
        }
        if (nowA + nowC > C)
        {
            q.push({nowA - (C - nowC), {nowB, C}});
        }
        else
        {
            q.push({0, {nowB, nowA + nowC}});
        }

        // B -> A / C
        if (nowA + nowB > A)
        {
            q.push({A, {nowB - (A - nowA), nowC}});
        }
        else
        {
            q.push({nowA + nowB, {0, nowC}});
        }
        if (nowC + nowB > C)
        {
            q.push({nowA, {nowB - (C - nowC), C}});
        }
        else
        {
            q.push({nowA, {0, nowB + nowC}});
        }

        if (nowA + nowC > A)
        {
            q.push({A, {nowB, nowC - (A - nowA)}});
        }
        else
        {
            q.push({nowA + nowC, {nowB, 0}});
        }
        if (nowB + nowC > B)
        {
            q.push({nowA, {B, nowC - (B - nowB)}});
        }
        else
        {
            q.push({nowA, {nowB + nowC, 0}});
        }
    }

    sort(list.begin(), list.end());
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << ' ';
    }
}

int main()
{
    fastIO();
    solve();
}
