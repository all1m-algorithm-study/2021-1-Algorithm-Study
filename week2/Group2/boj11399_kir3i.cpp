#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    scanf("%d", &N);
    int P[N];

    for(int i =0; i<N; i++)
        scanf("%d", &P[i]);

    sort(P, P+N);
    int sps = 0;
    int s = 0;

    for(int i = 0; i<N; i++) {
        for(int j = 0; j<=i; j++)
            s = s+P[j];
        sps = sps + s;
        s = 0;
    }

    printf("%d", sps);
    return 0;
}
