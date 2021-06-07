/*
* 1. 영역 내의 최소값, 최대값을 계산한다.
* 2. 최소값 ~ 최대값 내에 있는 모든 기준값에 대해 DFS 탐색 후 영역의 개수를 구한다.
* 
* 주의) 최소 안전 구역은 1개
* 
* 시간복잡도 = O(n^2) (n = 구역의 가로, 세로 길이)
*/

#include <iostream>
#include <vector>

using namespace std;

int area[102][102] = { 0 };
int direction[2][4] = { {-1, 1, 0, 0}, {0 ,0, -1, 1} };

void dfs(bool (*visited)[102], int x, int y, int level) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int next_x = x + direction[0][i];
        int next_y = y + direction[1][i];

        if (!visited[next_x][next_y] && area[next_x][next_y] > level) 
            dfs(visited, next_x, next_y, level);
    }
}

int main(){
    int n;
    int min_val = 100;
    int max_val = 0;
    int max_area = 1;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> area[i][j];
            max_val = max(max_val, area[i][j]);
            min_val = min(min_val, area[i][j]);
        }
    }

    for (int x = min_val; x < max_val; x++) {
        int area_cnt = 0;
        bool visited[102][102] = { false };

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (!visited[i][j] && area[i][j] > x) {
                    dfs(visited, i, j, x);
                    area_cnt += 1;
                }
            }
        }
        max_area = max(max_area, area_cnt);
    }
    cout << max_area;
}
