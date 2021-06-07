/*
* 1. 탐색은 DFS로 진행
* 2. 다음에 이동할 지점의 알파벳을 방문 표시
* 3. DFS 탐색 후 다음에 이동할 알파벳 방문 표시 해제
* 4. 탐색동안 가능한 경우들 중 가장 큰 값을 비교 (cnt 배열에 저장)
* 
* 주의) 매개변수 copy를 사용하면 시간 초과 발생
* 
* 시간복잡도 = O(n^2)
*/

#include <iostream>
#include <vector>

using namespace std;

vector<string> board;
vector<vector<int>> cnt;
int r, c;
int direction[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };

void dfs(vector<bool> &alphabet, int x, int y, int val) {
    cnt[x][y] = max(cnt[x][y], val);

    for (int i = 0; i < 4; i++) {
        int next_x = x + direction[0][i];
        int next_y = y + direction[1][i];

        if (next_x >= 0 && next_x < r && next_y >= 0 && next_y < c) {
            if (!alphabet[board[next_x][next_y] - 'A']) {
                alphabet[board[next_x][next_y] - 'A'] = true;
                dfs(alphabet, next_x, next_y, val + 1);
                alphabet[board[next_x][next_y] - 'A'] = false;
            }
        }
    }
}

int main() {
    string input;
    vector<bool> alphabet(26, false);
    int ans = 0;

    cin >> r >> c;
    cnt.resize(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++) {
        cin >> input;
        board.push_back(input);
    }

    alphabet[board[0][0] - 'A'] = true;
    dfs(alphabet, 0, 0, 1);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) 
            ans = max(ans, cnt[i][j]);

    cout << ans;
}
