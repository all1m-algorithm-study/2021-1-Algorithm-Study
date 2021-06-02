#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int map[301][301];
int zero[301][301];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[301][301];

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs(int x, int y){
    visited[x][y] = true;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx <0 || nx >=N || ny <0 || ny>=M){
            continue;
        }

        if(!visited[nx][ny] && map[nx][ny] >= 1){
            dfs(nx, ny);
        }
    }
}

bool isFinish(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j] != 0){
				return false;
			}
		}
	}
	return true;
}

bool isVictory(){
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!visited[i][j] && map[i][j] > 0){
                dfs(i, j);
                cnt++;

                if(cnt == 2){
                    return true;
                }
            }
        }
    }
    return false;
}

void zeroMake(){
	memset(zero, 0, sizeof(zero));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == 0){
                if(i-1 >= 0){
                    zero[i-1][j]++;
                }
                if(i+1 < N){
                    zero[i+1][j]++;
                }
                if(j+1 < M){
                    zero[i][j+1]++;
                }
                if(j-1 >= 0){
                    zero[i][j-1]++;
                }
            }
        }
    }
}

void timeFlow(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] > 0){
                map[i][j] -= zero[i][j];

                if(map[i][j] < 0) map[i][j] = 0;
            }
        }
    }
}

void solve(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M;j++){
            cin >> map[i][j];
        }
    }

    int time = 0;
    bool flag = false;
    while(true){
    	if(isFinish()){
    		break;
    	}
    	
        if(isVictory()){
            cout << time;
            flag = true;
            break;
        }
        zeroMake();
        timeFlow();
        time++;
    }
    
    if(!flag){
    	cout << "0";
    }
}

int main(){
    fastIO();
    solve();
}