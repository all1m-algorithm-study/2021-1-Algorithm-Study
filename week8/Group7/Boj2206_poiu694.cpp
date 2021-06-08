#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct me{
    int moveCnt;
    int isBreak;
    int x;
    int y;
};

int map[1001][1001];
int visited[1001][1001][2];
int dx[4] = {1, 0, -1, 0}; int dy[4] = {0, 1, 0, -1};
queue<me> q;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// pq: moveCnt, isBreak? x, y
int bfs(int N, int M){
    q.push({1,0, 0, 0});
    
    if(N == 1 && M == 1) return 1;
    
    int minMove = 10000001;
    while(!q.empty()){
        int nowMoveCnt = q.front().moveCnt;
        int isBreak = q.front().isBreak;
        int x = q.front().x;
        int y =  q.front().y;
        q.pop();
        
        if(x == N-1 && y == M-1){
            minMove = minMove < nowMoveCnt ? minMove : nowMoveCnt;
            continue;
        }
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= M){
                continue;
            }
            
            if(map[nx][ny] == 1 && isBreak == 0){
                if(visited[nx][ny][1] > nowMoveCnt + 1){
                    visited[nx][ny][1] = nowMoveCnt + 1;
                    q.push({nowMoveCnt+1, isBreak + 1, nx, ny});
                }
            }
            
            if(map[nx][ny] == 1) continue;
            
            if(visited[nx][ny][isBreak] > nowMoveCnt + 1){
                visited[nx][ny][isBreak] = nowMoveCnt + 1;
                q.push({nowMoveCnt +1, isBreak, nx, ny});
            }
        }
    }
    
    return minMove;
}

void solve(){
    memset(map, 0, sizeof(map));
    memset(visited, 1, sizeof(visited));
    
    int N, M;
    cin >> N >> M;
    
    string str;
    for(int i=0; i<N; i++){
        cin >> str;
        for(int j=0; j<str.length(); j++){
            map[i][j] = str[j] - '0';
        }
    }
    int ans = bfs(N, M);
    if(ans == 10000001){
        cout << -1;
    }else{
        cout << ans;
    }
}

int main(){
    fastIO();
    solve();
}
