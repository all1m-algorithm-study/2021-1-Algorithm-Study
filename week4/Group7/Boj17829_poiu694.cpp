#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N;
int map[1025][1025];

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void cutArea(int size)
{
    if (size == 1)
    {
        cout << map[0][0];
        return;
    }

    for (int i = 0; i < size; i += 2)
    {
        for (int j = 0; j < size; j += 2)
        {
            int a = map[i][j] > map[i][j + 1] ? map[i][j] : map[i][j + 1];
            int b = map[i][j] < map[i][j + 1] ? map[i][j] : map[i][j + 1];
            int c = map[i + 1][j] > map[i + 1][j + 1] ? map[i + 1][j] : map[i + 1][j + 1];
            int d = map[i + 1][j] < map[i + 1][j + 1] ? map[i + 1][j] : map[i + 1][j + 1];

            int second = a < c ? a : c;
            if (second == a)
            {
                second = a > d ? a : d;
            }
            else if (second == c)
            {
                second = c > b ? c : b;
            }

            map[i / 2][j / 2] = second;
        }
    }

    cutArea(size / 2);
}

void solve()
{
    cin >> N;

    // input
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    // size가 1이 될 때까지
    cutArea(N);
}

int main()
{
    fastIO();
    solve();
}