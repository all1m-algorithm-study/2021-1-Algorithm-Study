#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> A, B;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve()
{
    cin >> N >> M;
    A.resize(N);
    B.resize(M);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int j = 0; j < M; j++)
    {
        cin >> B[j];
    }
    vector<int> list;
    int i = 0, j = 0;
    while (true)
    {
        if (i == N || j == M)
        {
            break;
        }

        if (A[i] > B[j])
        {
            list.push_back(B[j]);
            j++;
            continue;
        }
        else
        {
            list.push_back(A[i]);
            i++;
            continue;
        }
    }

    while (i < N)
    {
        list.push_back(A[i++]);
    }
    while (j < M)
    {
        list.push_back(B[j++]);
    }

    for (int i = 0; i < N + M; i++)
    {
        cout << list[i] << " ";
    }
}

int main()
{
    fastIO();
    solve();
}