#include <bits/stdc++.h>
using namespace std;

int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        if (i + (i / 1000000) + ((i % 1000000) / 100000) + ((i % 100000) / 10000) + ((i % 10000) / 1000) + ((i % 1000) / 100) + ((i % 100) / 10) + ((i % 100) % 10) == n) {
            cout << i;
            return 0;
        }
        else if (i == n) {
            cout << 0;
            return 0;
        }
    }
   
}