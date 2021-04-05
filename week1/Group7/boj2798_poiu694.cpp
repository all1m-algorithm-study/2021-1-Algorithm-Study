#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int num[101];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> num[i];
    }
}

void solve(){
    sort(num, num+N);
        
    int big = num[0] + num[1] + num[2]; 
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            for(int k=j+1; k<N; k++){
                int sum = num[i]+num[j]+num[k];
                
                // 값을 넘었으므로 더이상 진행할 필요 x
                if(sum > M){
                    break;	
                }
                else if(sum <= M) {
                    big = max(big, sum);
                }
            }
        }
    }

    cout << big;
}

int main(){
	init();
    input();
    solve();
}
