#include <iostream>
#include <vector>

using namespace std;

int answer = 0;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs(vector<int> graph[], bool visited[], int node){
    answer++;
    visited[node] = true;
 
    for(int i=0; i<graph[node].size(); i++){
        int nextNode = graph[node][i];

        if(!visited[nextNode]){
            dfs(graph, visited, nextNode);
        }
    }   
}

void solve(){
    int N, M;
    cin >> N >> M;
    vector<int> graph[N+1];
    bool visited[N+1];

    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }    
    dfs(graph, visited, 1);

    cout << answer;
}

int main(){
    fastIO();
    solve();
}