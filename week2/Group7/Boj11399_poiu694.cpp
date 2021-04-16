#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> list;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    cin >> N;

    int temp;
    for(int i=0; i<N; i++){
        cin >> temp;
        list.push_back(temp);
    }
}

void solve(){
    sort(list.begin(), list.end()); // 오름차순

    int sum = 0;
    for(int i=0; i<N; i++){
        sum += (N-i) * list[i];
    }

    cout << sum;
}

int main(){
	fastIO();
    input();
    solve();
}