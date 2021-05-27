#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[100001];
int parent[100001];
bool visited[100001];

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs(int node){
    visited[node] = true;

    for(int i=0; i<graph[node].size(); i++){
        int nextNode = graph[node][i];
        parent[nextNode] = node;
        if(!visited[nextNode]){
            dfs(nextNode);
        }
    }
}

void solve(){
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        int parent, child;
        cin >> parent >> child;
        graph[parent].push_back(child);
    }

    dfs(1);

    for(int i=2; i<=N; i++){
        cout << parent[i] << '\n';
    }
}

int main(){
    fastIO();
    solve();
}