#include <iostream>
#include <stack>
using namespace std;

string reverseSubstringBetweenEachPairOfParenthesis(string &str) {
    string ans = "";
    stack<char> st;

    for (auto &ch : str) {
        if (ch != ')') {
            st.push(ch);
        } else {
            string dummyStr = "";

            while (st.top() != '(') {
                dummyStr += st.top();
                st.pop();
            }

            st.pop();
            int n = dummyStr.length();
            for (int j = 0; j < n; j++) {
                st.push(dummyStr[j]);
            }
        }
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

    string ans = reverseSubstringBetweenEachPairOfParenthesis(str);

    cout << ans << endl;
    return 0;
}