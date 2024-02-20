#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> ngeR(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n, 0);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        if (st.size() == 0) {
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

    vector<int> ans = ngeR(arr);

    for (auto &val : ans) {
        cout << val << " ";
    }
    return 0;
}