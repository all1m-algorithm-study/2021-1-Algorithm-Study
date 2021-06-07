#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[101];
bool visited[101];
int a, b, answer = -1;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs(int depth, int node){
    if(node == b){
        answer = depth - 1;
        return;
    }

    visited[node] = true;
    for(int i=0; i<graph[node].size(); i++){
        int nextNode = graph[node][i];
        if(!visited[nextNode]){
            dfs(depth+1, nextNode);
        }
    }
}

void solve(){
    int N, M;
    cin >> N >> a >> b >> M;

    for(int i=0; i<M; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }

    dfs(1, a);
    cout << answer;
}

int main(){
    fastIO();
    solve();
}