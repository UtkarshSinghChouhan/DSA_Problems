#include <iostream>
#include <stack>

using namespace std;

string minimumRemoveToMakeParenthesisValid(string &str) {
    string ans = "";
    stack<int> st;
    int n = str.length();

    for (int i = 0; i < n; i++) {
        char ch = str[i];
        if (ch == '(') {
            st.push(i);
        } else if (ch == ')') {
            if (st.empty()) {
                str[i] = '#';
                continue;
            }
            st.pop();
        }
    }

    while (!st.empty()) {
        str[st.top()] = '#';
        st.pop();
    }

    for (auto &ch : str) {
        if (ch != '#')
            ans += ch;
    }

    return ans;
}

int main() {
    string str;
    cin >> str;
    string ans = minimumRemoveToMakeParenthesisValid(str);

    cout << ans << endl;
    return 0;
}