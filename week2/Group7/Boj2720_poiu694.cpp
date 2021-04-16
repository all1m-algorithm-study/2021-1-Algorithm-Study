#include <iostream>
#include <vector>

using namespace std;

int T;
int list[4]; // Quater & Dime & Nickel & Penny
const int Quarter = 25;
const int Dime = 10;
const int Nickel = 5;
const int Penny = 1;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(){
    cin >> T;

    while(T--){ // TestCase개수만큼 반복
        int temp;
        cin >> temp;

        list[0] = temp / Quarter;
        temp %= Quarter;

        list[1] = temp / Dime;
        temp %= Dime;

        list[2] = temp / Nickel;
        temp %= Nickel;

        list[3] = temp / Penny ;

        for(int i=0; i<4; i++){
            cout << list[i] << " ";
        }

        cout << '\n';
    }
}

int main(){
    init();
    solve();
}