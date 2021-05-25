#include <iostream>

using namespace std;

int L, W, H, N;
int cnt = 0;
long long cubes[21]; // Ai = Bi
int pow[21]; // n = 2^n

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void make_pow(){
    pow[0] = 1;
    for(int i=1; i<20; i++){
        pow[i] = pow[i-1] * 2;
    }
}

bool findCube(int L, int W, int H)
{
    // BUBBLE SORT
    int temp;
    if(L > W){
        temp = L;
        L = W;
        W = temp;
    }
    if(W > H){
        temp = W;
        W = H;
        H = temp;
    }
    if(L > W){
        temp = L;
        L = W;
        W = temp;
    }

    if(L == 0){
        return true; // 깔끔하게 마무리
    }
    if(L == 1){
        cubes[0] = cubes[0] - (long long)(W*H);
        cnt += (long long) (W * H);
        return (cubes[0] >= 0) ? true : false;
    }

    for(int i=19; i>=0; i--){
        if(cubes[0] == 0) continue;
        if(L < pow[i]) continue;
        int x = pow[i];
        cubes[i]--; 
        cnt++;
        if(!findCube(L-x, W, H)) return false;
        if(!findCube(x, x, H-x)) return false;
        if(!findCube(x, W-x, H)) return false;
        return true;
    }

    return false;
}

void solve()
{
    cin >> L >> W >> H;
    make_pow();
    cin >> N;
    int size, cnt;
    for (int i = 0; i < N; i++)
    {
        cin >> size >> cnt;
        cubes[size] = cnt;
    }

    if(!findCube(L,W,H)){
        cout << '-1';
    }else{
        cout << cnt;
    }
}

int main()
{
    fastIO();
    solve();
}