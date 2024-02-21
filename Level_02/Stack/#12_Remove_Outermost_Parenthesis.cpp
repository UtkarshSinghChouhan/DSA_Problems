#include <iostream>
#include <stack>

using namespace std;

string removeOutermostParenthesis(string &str) {
    string ans = "";
    stack<char> st;

    for (char &ch : str) {
        // if opening bracket
        if (ch == '(') {
            // push
            st.push('(');
            // check before adding to the answer
            if (st.size() > 1) {
                ans += '(';
            }

        }

        // if closing bracket
        else {

            // pop
            st.pop();
            // check before adding to the answer
            if (st.size() != 0) {
                ans += ')';
            }
        }
    }

    return ans;
}

int main() {
    string str;
    cin >> str;

    string ans = removeOutermostParenthesis(str);

    cout << '"' + ans + '"' << endl;

    return 0;
}

// INPUT
// ()

// OUTPUT
// ""

// INPUT
// (()())(())(()(()))

// OUTPUT
// "()()()()(())"