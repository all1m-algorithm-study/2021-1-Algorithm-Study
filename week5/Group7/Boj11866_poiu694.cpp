#include <iostream>
#include <queue>

using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(){
    int N, K;
    cin >> N >> K;

    queue<int> q;
    int temp;
    for(int i=1; i<=N; i++){
        cin >> temp;
        q.push(temp);
    }

    int cnt = 0;
    cout << '<';
    while(!q.empty()){
        int num = q.front();
        q.pop();

        cnt++;
        if(cnt == K){
            cout << num << ', ';
        }else{
            q.push(num);
        }
    }
    cout << '>';
}

int main(){
    fastIO();
    solve();
}