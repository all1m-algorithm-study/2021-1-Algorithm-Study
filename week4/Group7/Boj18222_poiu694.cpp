#include <iostream>
#include <cmath>

using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int mos(long long num){
    if(num == 0){
        return 0; 
    }else{
        return !mos(num - (int)(pow(2, log2(num))));
    }
}

void solve(){
    long long N;
    cin >> N;

    cout << mos(N-1);
}

int main(){
    fastIO();
    solve();
}