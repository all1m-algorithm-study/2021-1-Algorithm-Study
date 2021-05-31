#include <stdio.h>
#include <algorithm>

/*
    [Silver 2]
    222-풀링

    입력:
    N(N=2^k)
    N*N 행렬에 대한 입력값...

    과정:
    [1] 행렬을 2*2로 나눈다.
        
        - 어떻게 나누지?
            => 열로 먼저 2씩 나눈다.
            => 행으로 각 열을 2씩 나눈다.

        - 그래서 나눠서, 계산했다한들,
            => 4배 줄어든 행렬은 너무 불편하지 않나?
               (웬지 새로운 행렬을 할당할 것 같진 않다. 그리고 너무 오래 걸릴듯.)

            => 분할 정복이 으레 그렇듯, 최소 단위로 나누는 과정을 한 번에 할 게 아니라,
               그러니까, divide, merge 이렇게 내려 갔다가 올라 오는 과정이 있어야 한다.
               내려 가고, 올라 가는건 범위가 2배씩 증감하면 될 것이다.

                - 그럼 2배로 작아지게 해야 하는데, 그건 어떻게 하지?

    => 4등분이 답인 거 같은데용
    => 항상 4등분이기 때문에, y2-y1, x2-x1이 동일하다.

    출력:
    1x1에 있는 숫자.
    
*/

using namespace std;

int N;
int M[1024][1024];

// [x1, x2), [y1, y2)
int divide(int x1, int x2, int y1, int y2)
{
    if (x2 - x1 > 2) // 계속 나눠야 함: 2칸 이상씩 있음. (즉, 8*8, 4*4 등의 형태를 갖고 있음.)
    {
        int midX = (x2 + x1) / 2;
        int midY = (y2 + y1) / 2;
        int arr[4];
        arr[1] = divide(x1, midX, y1, midY); // 2사분면
        arr[0] = divide(midX, x2, y1, midY); // 1사분면
        arr[2] = divide(x1, midX, midY, y2); // 3사분면
        arr[3] = divide(midX, x2, midY, y2); // 4사분면
        sort(arr, arr + 4);
        return arr[2]; // 뒤에서 2번째.
    }
    else // merge 단계 (2x2 행렬) - 2번째로 큰 원소 반환
    {
        int arr[4];
        arr[0] = M[x1][y1];
        arr[1] = M[x1 + 1][y1];
        arr[2] = M[x1][y1 + 1];
        arr[3] = M[x1 + 1][y1 + 1];
        sort(arr, arr + 4);
        return arr[2]; // 뒤에서 2번째.
    }
}

int main()
{
    // 1. 단순 입력
    int i, j;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            scanf("%d", &M[i][j]);

    // 2. 분할정복
    int result = divide(0, N, 0, N);
    printf("%d\n", result);
    return 0;
}
