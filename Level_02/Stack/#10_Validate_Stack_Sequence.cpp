#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool validateStackSequence(vector<int> &pushed, vector<int> &popped) {
    int n = pushed.size();
    int i = 0, j = 0;
    stack<int> st;

    while (i < n) {
        st.push(pushed[i]);
        i++;

        while (!st.empty() && j < n && st.top() == popped[j]) {
            st.pop();
            j++;
        }
    }

    return st.empty();
}

int main() {
    int n;
    cin >> n;
    vector<int> pushed;
    vector<int> popped;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        pushed.push_back(val);
    }

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        popped.push_back(val);
    }

    if (validateStackSequence(pushed, popped)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}

// INPUT
// 5
// 1 2 3 4 5
// 4 5 3 2 1

// TRUE

// INPUT
// 5
// 1 2 3 4 5
// 4 3 5 1 2

// FALSE