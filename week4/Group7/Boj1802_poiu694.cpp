#include <iostream>

using namespace std;

int N;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool is_can(string str){
    int len = str.length();

    int i = 1;
    while(true){
        if(str[len + i] != str[len - i]){
            return false;
        }

        i++;
        if(i * 2 == len){
            break;
        }
    }
    return true;
}

void solve(){
    cin >> N;

    string str;
    while(N--){
        cin >> str;

    }
}

int main(){
    fastIO();
    solve();
}