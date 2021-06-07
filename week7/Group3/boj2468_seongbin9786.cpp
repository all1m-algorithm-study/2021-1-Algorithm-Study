#include <iostream>

#define N 100

using namespace std;

const int px[] = {1, -1, 0, 0};
const int py[] = {0, 0, -1, 1};
int SIZE, cur_island, cur_height;

int visited2468[N][N] = {0}; // 시간 절약 아이디어
int matrix2468[N][N] = {0};

void DFS(int x, int y)
{
    if (visited2468[x][y] >= cur_height)
        return;

    visited2468[x][y] = cur_height;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + px[i];
        int ny = y + py[i];
        if (nx < 0 || ny < 0 || nx >= SIZE || ny >= SIZE)
            continue;
        if (visited2468[nx][ny] >= cur_height || matrix2468[nx][ny] - cur_height <= 0)
            continue;
        DFS(nx, ny);
    }
}

int main()
{
    int i, j, tmp, max = 0, max_island = 1;
    cin >> SIZE;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            cin >> tmp;
            matrix2468[i][j] = tmp;
            max = max < tmp ? tmp : max;
        }
    }

    for (cur_height = 1; cur_height < max; cur_height++)
    {
        cur_island = 0;
        for (i = 0; i < SIZE; i++)
            for (j = 0; j < SIZE; j++)
                if (visited2468[i][j] < cur_height && matrix2468[i][j] - cur_height > 0)
                {
                    DFS(i, j);
                    cur_island++;
                }
        max_island = max_island < cur_island ? cur_island : max_island;
    }
    cout << max_island << "\n";
    return 0;
}
