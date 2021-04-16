#include <iostream>
#include <cmath>

using namespace std;

int N, R, C;
int temp = 0;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    cin >> N >> R >> C;
}

void cutArea(int i, int j, int num){
    if(num == 1){
        if(i == R && j == C){
            cout << temp;
            return;
        }
        temp++;
        return;
    }

    for (int x = i; x < i + num; x += (num/2)) {
            for (int y = j; y < j + num; y +=(num/2)) {
                cutArea(x, y, (num/2));
            }
        }
}

void solve(){
    cutArea(0, 0, pow(2, N));
}

int main(){
    fastIO();
    input();
    solve();
}