#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int ok[10][10][10];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int x=1; x<10; x++)
        for(int y=1; y<10; y++)
            for(int z=1; z<10; z++)
                ok[x][y][z] = 1;

    for(int i=0; i<10; i++)
        ok[i][i][i] = 0;
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++) {
            ok[i][j][j] = 0;
            ok[j][i][j] = 0;
            ok[j][j][i] = 0;
        }

    int q;  cin >> q;
    while(q--) {
        string query;
        int s, b;   cin >> query >> s >> b;

        for(int x=0; x<10; x++)
            for(int y=0; y<10; y++)
                for(int z=0; z<10; z++) {
                    if(!ok[x][y][z])
                        continue;
                    int chkS = 0, chkB = 0;
                    if(query[0] - '0' == x)
                        chkS++;
                    else if(query[1] - '0' == x || query[2] - '0' == x)
                        chkB++;

                    if(query[1] - '0' == y)
                        chkS++;
                    else if(query[0] - '0' == y || query[2] - '0' == y)
                        chkB++;

                    if(query[2] - '0' == z)
                        chkS++;
                    else if(query[1] - '0' == z || query[0] - '0' == z)
                        chkB++;

                    if(chkS != s || chkB != b)
                        ok[x][y][z] = 0;
                }
    }

    int cnt = 0;
    for(int x=0; x<10; x++)
        for(int y=0; y<10; y++)
            for(int z=0; z<10; z++)
                if(ok[x][y][z])
                    cnt++;

    cout << cnt;
}