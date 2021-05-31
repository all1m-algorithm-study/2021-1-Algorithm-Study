#include <iostream>
#include <stack>

using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {
    string target;
    cin >> target;

    stack<char> st;
    for (int i = 0; i < target.length(); i++) {
        if ('A' <= target[i] && target[i] <= 'Z') {
            cout << target[i];
        }
        else {
            if (target[i] == '(') {
                st.push(target[i]);
            }
            else if (target[i] == '+' || target[i] == '-') {
                while (!st.empty() && st.top() != '(') {
                    cout << st.top();
                    st.pop();
                }
                st.push(target[i]);
            }
            else if (target[i] == '*' || target[i] == '/') {
                while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                    cout << st.top();
                    st.pop();
                }
                st.push(target[i]);
            }
            else {
                while (!st.empty() && st.top() != '(') {
                    cout << st.top();
                    st.pop();
                }
                st.pop();
            }
        }
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }

}

int main() {
    fastIO();
    solve();
}