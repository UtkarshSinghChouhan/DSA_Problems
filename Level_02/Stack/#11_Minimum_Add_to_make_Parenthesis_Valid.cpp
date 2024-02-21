#include <iostream>
#include <stack>

using namespace std;

// ALGO
// Remove all the valid-parenthesis-string from the stack, then the remaing
// characters in the stack will require charcters to make the string valid(this
// will give us the count of the required characters)

int minimumAddtoMakeParenthesisValid(string &str) {

    stack<char> st;

    for (char &ch : str) {
        if (ch == '(') {
            st.push('(');
        } else if (ch == ')') {

            if (st.size() == 0) {
                st.push(')');
            } else {
                if (st.top() == '(') {
                    st.pop();
                } else {
                    st.push(')');
                }
            }
        }
    }

    return st.size();
}

int main() {
    string str;
    cin >> str;

    cout << minimumAddtoMakeParenthesisValid(str);

    return 0;
}

// TEST CASE - 1
// input
// (()))(

// output
// 2

// TEST CASE - 2
// input
// ()))((

// output
// 4

// TEST CASE - 3
// input
// ()())(()))

// output
// 2