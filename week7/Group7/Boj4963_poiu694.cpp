#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int R, C, T;
char map[101][101];
bool visited[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int answer = -1;

void dfs(int depth, int now, int x, int y){
    if(depth == T){
        answer = max(answer, now);
        return;
    }

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >=R || ny < 0 || ny >=C){
            continue;
        }

        if(map[nx][ny] == '#' || visited[nx][ny]){
            continue;
        }

        if(map[nx][ny] == 'S'){
        	visited[nx][ny] = true;
            dfs(depth+1, now +1, nx, ny);
            visited[nx][ny] = false;
        }else{
            visited[nx][ny] = true;
            dfs(depth+1, now, nx, ny);
            visited[nx][ny] = false;
        }
    }
}

int main(){
    cin >> R >> C >> T;

    int sx, sy;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> map[i][j];

            if(map[i][j] == 'G'){
                sx = i;
                sy = j;
            }
        }
    }

    dfs(0, 0, sx, sy);
    cout << answer;
}