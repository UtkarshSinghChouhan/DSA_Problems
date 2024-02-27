#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

string remove_duplicate_letters(string &str) {
    int n = str.length();
    string ans = "";
    stack<char> st;
    map<char, int> m;
    for (auto &ch : str) {
        m[ch]++;
    }
    vector<int> v(26, false);

    for (int i = 0; i < n; i++) {
        char ch = str[i];
        m[ch]--;
        if (v[ch - 'a'] == true) {
            continue;
        }

        while (!st.empty() && st.top() > ch && m[ch] > 0) {
            v[st.top() - 'a'] = false;
            st.pop();
        }

        v[ch - 'a'] = true;
        st.push(ch);
    }

    while (!st.empty()) {
        ans = st.top() + ans;
        st.pop();
    }

    return ans;
}

int main() {

    string str;
    cin >> str;

    cout << remove_duplicate_letters(str);

    return 0;
}