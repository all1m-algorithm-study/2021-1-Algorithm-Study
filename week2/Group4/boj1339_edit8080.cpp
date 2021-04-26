/*
* 1. 각 알파벳의 자릿수를 계수로 설정 => 계수의 합
* 2. 계수를 내림차순으로 정렬한 후 각 계수에 9부터 0까지의 가중치를 곱함 (알파벳 설정)
*
* 시간복잡도 = O(nlogn + nm) (n: word 개수, m: word 길이)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define SIZE 26

using namespace std;

int main(){
    int n;
    string word;
    vector<string> words;
    vector<int> alphabet(SIZE, 0);
    vector<int> coefficient;

    cin >> n;

    words.resize(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];
    
    for (int i = 0; i < n; i++) {
        int length = (int)words[i].length();
        for (int j = 0; j < length; j++) {
            alphabet[words[i].at(j) - 'A'] += (int)pow(10, length - j - 1);
        }
    }
    for (int i = 0; i < SIZE; i++) 
        if (alphabet[i] != 0)
            coefficient.push_back(alphabet[i]);    

    sort(coefficient.begin(), coefficient.end(), greater<int>());

    int sum = 0;
    int value = 9;

    for (int i = 0; i < (int)coefficient.size(); i++)
        sum += coefficient[i] * (value--);

    cout << sum;
}