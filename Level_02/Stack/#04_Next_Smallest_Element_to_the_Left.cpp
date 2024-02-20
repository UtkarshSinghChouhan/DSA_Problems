#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nseL(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        if (!st.size()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }

        st.push(arr[i]);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    vector<int> ans = nseL(arr);

    for (auto &val : ans) {
        cout << val << " ";
    }

    return 0;
}