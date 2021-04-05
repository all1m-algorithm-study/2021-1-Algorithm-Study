#include <iostream>
#include <string.h>

using namespace std;

string target;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> target;
}

// is_Palindorme ?
bool is_Palindrome(string str) {
    int len = str.length();

    if (len == 1) {
        return true; // str.length() == 1 -> Always Palindrome
    }

    for (int i = 0; i < len; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }

    return true;
}

int appendChar(string str) {
    if (is_Palindrome(str)) {
        return 0;
    }

    str = str.substr(1); // 맨 앞 문자 제거
    return 1 + appendChar(str);
}

// 뒤에 붙이는 Palindrome
// Not Palindrome -> 맨 앞 문자를 추가시켜야 한다. -> 다음단계
// Not Palindrome -> 2번째 문자를 추가시켜야 한다. -> 반복
void solve() {
    int needCnt = appendChar(target);
    

    cout << target.length() + needCnt;
}

int main() {
    init();
    input();
    solve();
}