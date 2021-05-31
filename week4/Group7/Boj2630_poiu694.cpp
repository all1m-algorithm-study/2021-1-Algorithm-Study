#include <iostream>

using namespace std;

int N;
int color[2] = {0, 0};
int map[129][129];

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool is_area(int x, int y, int size, int color)
{
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (color != map[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

void cutArea(int x, int y, int size)
{
    if (is_area(x, y, size, map[x][y]))
    {
        color[map[x][y]]++;
        return;
    }

    for (int i = x; i < x + size; i += (size / 2))
    {
        for (int j = y; j < y + size; j += (size / 2))
        {
            cutArea(i, j, (size / 2));
        }
    }
}

void solve()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    cutArea(0, 0, N);

    cout << color[0] << '\n'
         << color[1];
}

int main()
{
    fastIO();
    solve();
}