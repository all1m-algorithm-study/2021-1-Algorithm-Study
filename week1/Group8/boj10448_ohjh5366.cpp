#include <bits/stdc++.h>
using namespace std;

int k;
int num;
int tri[100];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;

    for (int i = 1; i < 100; i++) {
        tri[i] = (i * (i + 1)) / 2;
    }

    for (int i = 0; i < k; i++) {
        int flag = 0;
        cin >> num;
        for (int x = 1; x < 100; x++) {
            for (int y = 1; y < 100; y++) {
                for (int z = 1; z < 100; z++) {
                    if (num == tri[x] + tri[y] + tri[z]) {
                        cout << 1 << '\n';
                        flag = 1;
                        break;
                    }
                    else if (x == 99 && y == 99 && z == 99) {
                        cout << 0 << '\n';
                    }
                }
                if (flag) {
                    break;
                }
            }
            if (flag) {
                break;
            }
        }

    }
   
}