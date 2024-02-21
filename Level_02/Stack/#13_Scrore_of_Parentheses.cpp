#include <iostream>
#include <stack>
using namespace std;

int scoreOfParentheses(string str) {
    int ans = 0;
    stack<int> st;

    for (auto &ch : str) {
        if (ch == '(') {
            st.push(-1); // we have pick -1 to represent the opening bracket
        } else {
            if (st.top() == -1) {
                st.pop();
                st.push(1);
            } else {
                int cnt = 0;

                while (st.top() != -1) {
                    cnt += st.top();
                    st.pop();
                }

                st.pop();

                st.push(2 * cnt);
            }
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main() {
    string str;
    cin >> str;

    int ans = scoreOfParentheses(str);

    cout << ans << endl;

    return 0;
}

// INPUT
// (()(()))

// OUTPUT
// 6