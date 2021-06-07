#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int map[101][101];
bool visited[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs(int x, int y, int water){
    visited[x][y] = true;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >=0 && ny >= 0 && nx < 100 && ny<100){
            if(!visited[nx][ny] && map[nx][ny] > water){
                dfs(nx, ny, water);
            }
        }
    }
}

void solve(){
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }

    int water = 0;
    int answer = 0;
    while(water != 101){
        memset(visited, false, sizeof(visited));

        int cnt = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(map[i][j] > water && !visited[i][j]){
                    cnt++;
                    dfs(i, j, water);
                }
            }
        }
        answer = max(answer, cnt);
        water++;
    }
    
    cout << answer;
}

int main(){
    fastIO();
    solve();
}