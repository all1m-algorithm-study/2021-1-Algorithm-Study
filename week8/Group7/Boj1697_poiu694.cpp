#include <iostream>
#include <queue>

using namespace std;

#define MAX 100001
int N, K;
bool check[MAX] = { false };
queue<pair<int, int>> q;

int bfs(){
	q.push({N, 0}); // 시작점 Queue 삽입
	check[N] = true;
	    
    while(!q.empty()){
        int now = q.front().first; // 현재 위치
	    int time = q.front().second; // 현재 시간
	    q.pop();
	    
	    int x1 = now + 1;
	    int x2 = now - 1;
	    int x3 = now * 2;
	    
        // 종료 조건
        if(now == K){
            return time;
        }
        
        if(x1 <= MAX && !check[x1]){
        	check[x1] = true;
        	q.push({x1, time+1});
        }
        
        if(0 <= x2 && !check[x2]){
        	check[x2] = true;
        	q.push({x2, time+1});
        }
        
        if(x3 <= MAX && !check[x3]){
        	check[x3] = true;
        	q.push({x3, time+1});
        }
    }
}

void input(){
    cin >> N >> K;
}

int main(){
    input();
    cout << bfs();
}