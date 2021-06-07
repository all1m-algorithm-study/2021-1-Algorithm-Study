#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int R, C, answer = -1;
char map[21][21];
bool visitedMap[21][21];
bool visitedAlpha[27];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs(int x, int y, int cnt){
    answer = max(answer, cnt);

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= R || ny < 0 || ny >= C){continue;}

        if(!visitedMap[nx][ny] && !visitedAlpha[map[nx][ny] -'A']){
        	visitedMap[nx][ny] = true; visitedAlpha[map[nx][ny] - 'A'] = true;
            dfs(nx, ny, cnt + 1);
            visitedMap[nx][ny] = false; visitedAlpha[map[nx][ny] - 'A'] = false;
        }
    }
}

void solve(){
    cin >> R >> C;
    string temp;
    for(int i=0; i<R; i++){
        cin >> temp;
        for(int j=0; j<temp.length(); j++){
            map[i][j] = temp[j];
        }
    }
	visitedMap[0][0] = true; visitedAlpha[map[0][0] -'A'] = true;
    dfs(0, 0, 1);
    cout << answer;
}

int main(){
    fastIO();
    solve();
}