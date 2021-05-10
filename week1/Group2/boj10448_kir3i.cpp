#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int isOk[1001];
int eureka[45];
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int i=0; i<45; i++)
        eureka[i] = i*(i+1) / 2;

    for(int x=1; x < 45; x++)
        for(int y=1; y < 45; y++)
            for(int z=1; z<45; z++)
                if(eureka[x] + eureka[y] + eureka[z] < 1001)
                    isOk[eureka[x] + eureka[y] + eureka[z]] = 1;

    int T;  cin >> T;
    while(T--) {
        int k;  cin >> k;
        cout << isOk[k] << "\n";
    }
}