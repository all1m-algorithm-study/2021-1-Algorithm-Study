#include <iostream>

using namespace std;

int map[1001][1001];
bool visited[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool flag = false;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs(int x, int y, int N, int M){
    if(x == N-1){
        flag = true;
        return;
    }

    visited[x][y] = true;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >=N || ny >= M){
            continue;
        }
        if(map[nx][ny] == 1 || visited[nx][ny]){
        	continue;
        }
		
		dfs(nx, ny, N, M);
    }
}

void solve(){
    int N, M;
    cin >> N >> M;
    string temp;
    for(int i=0; i<N; i++){
        cin >> temp;
        for(int j=0; j<temp.length(); j++){
        	map[i][j] = temp[j] - '0';
        }
    }

    for(int i=0; i<M; i++){
        if(map[0][i] == 0 && !visited[0][i]){
            dfs(0, i, N, M);
        }
    }

    if(flag){
        cout << "YES";
    }else{
        cout << "NO";
    }
}

int main(){
    fastIO();
    solve();
}