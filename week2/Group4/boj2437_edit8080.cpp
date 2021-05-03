/*
* 1. 입력값을 정렬 후 다음에 오는 값이 연속을 만들 수 있는 범위값인지 확인
* 2. 만약 연속을 만들지 못한다면 이전 탐색 범위의 최대값을 return
* 
* 시간복잡도 = O(nlogn) 
* 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long check(int n, vector<int> &weight) {
    long long max = 2;
    long long range = 1;

    for (int i = 1; i < n; i++) {
        if (weight[i] <= max) {
            range += weight[i];
            max = range + 1;
        }
        else 
            return max;        
    }
    return max;
}

int main(){
    int n;
    vector<int> weight;
    
    cin >> n;

    weight.resize(n);
    for (int i = 0; i < n; i++)
        cin >> weight[i]; 
    
    sort(weight.begin(), weight.end());

    if (weight[0] != 1)
        cout << '1';
    else
        cout << check(n, weight);    
}