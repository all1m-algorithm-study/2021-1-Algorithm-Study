#include <iostream>
#include <vector>

using namespace std;

int sum = 0;
vector<int> graph[501];
bool visited[501];

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs(int node, int depth){
    if(depth == 2){
        return;
    }

    sum++;
    vistied[node] = true;
    for(int i=0; graph[node].size(); i++){
        int nextPerson = graph[node][i];

        dfs(nextPerson, depth + 1);
    }
}

void solve(){
    int N, M;
    cin >> N >> M;

    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << sum;
}

int main(){
    fastIO();
    solve();
}