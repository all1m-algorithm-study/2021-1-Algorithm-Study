#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool is_palindrome(const string &x) {
    string reversed = x;
    reverse(reversed.begin(), reversed.end());

    return x == reversed;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string src; cin >> src;
    string reversed = src;
    reverse(reversed.begin(), reversed.end());
    int sz = src.size();
    for(int i=0; i<sz; i++) {
       if(is_palindrome(src + reversed.substr(sz-i, i))) {
           cout << sz+i;
           break;
       }
    }
}