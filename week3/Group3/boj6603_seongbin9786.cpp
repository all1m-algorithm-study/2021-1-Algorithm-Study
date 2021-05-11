#include <iostream>

/*
    [Silver 2]
    로또

    독일 로또는 {1, 2, ..., 49}에서 수 6개를 고른다.

    로또 번호를 선택하는데 사용되는 가장 유명한 전략은 
    49가지 수 중 k(k>6)개의 수를 골라 집합 S를 만든 다음 그 수만 가지고 번호를 선택하는 것이다.

    예를 들어, k=8, S={1,2,3,5,8,13,21,34}인 경우 이 집합 S에서 수를 고를 수 있는 경우의 수는 총 28가지이다. 
    ([1,2,3,5,8,13], [1,2,3,5,8,21], [1,2,3,5,8,34], [1,2,3,5,13,21], ..., [3,5,8,13,21,34])

    ----
    [IDEA]
    1. 아 이해 했음. nS=k인 집합에서 6개를 고른 모든 조합을 구하라

    2. 백트래킹 맞음. 대신 1~N이 아니라, A[0] ~ A[N-1] 을 고르기만 하면 됨.

    3. 백트래킹 아님. 백트래킹은 순열임. 우린 조합이 필요하므로, 순서까지 배제해야 함.
        => 한 번 쓴 조합을 어떻게 배제할 수 있을까?
        => 오름차순으로 나오게 하면 됨 ㅇㅇ
            => 왜 오름차순으로 나오게 하면 조합이 될까? 신기하네
    ----

    입력
    여러 개 테스트 케이스
    한 줄 단위
    k numbers_of_k...
    (오름차순)

    입력의 마지막 줄에는 0이 하나 주어진다. 

    출력
    이때, 사전 순으로 출력
    TC 사이에 빈 줄을 하나 출력
*/

using namespace std;

int N;               // 재귀함수 공유 변수
bool used[50] = {0}; // used, cur 이 S[i]<=49 이므로, 49까지 필요함

int nums[13] = {0};
int S[13] = {0}; // nSet < 13

void backtrack(int curIdx, int min)
{
    int i, j, num;
    // min=idx로 쓰면 됨
    for (i = min; i < N; i++)
    {
        // 1~N 대신 S[0]~S[N-1]
        num = S[i];
        // 숫자 사용 불가 시 PASS
        if (used[num])
            continue;

        // 해당 숫자 사용
        used[num] = true;
        nums[curIdx] = num;

        // 재귀부: 다음 자릿수로 이동
        if (curIdx < 6)
            // num이 아니라, i를 써야 함. idx니까
            backtrack(curIdx + 1, i);
        else
        {
            for (j = 1; j < 6; j++)
                cout << nums[j] << " ";
            cout << nums[j] << "\n";
        }

        // 이번 자리수로 돌아온 경우.
        // 다음 숫자를 쓸 예정이므로 현재 숫자 반납
        used[num] = false;
        nums[curIdx] = 0;
    }
}

int main()
{
    int i;
    while (true)
    {
        cin >> N;
        if (N == 0)
            break;
        for (i = 0; i < N; i++)
        {
            nums[i] = false;
            cin >> S[i];
        }
        for (i = 0; i < 50; i++)
            used[i] = 0;
        backtrack(1, 0);
        cout << "\n";
    }
    return 0;
}