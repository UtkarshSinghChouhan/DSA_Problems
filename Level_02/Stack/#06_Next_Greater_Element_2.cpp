#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

map<int, int> ngeR(vector<int> &arr) {
    int n = arr.size();
    stack<int> st;
    map<int, int> m;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        if (!st.size()) {
            m[arr[i]] = -1;
        } else {
            m[arr[i]] = st.top();
        }

        st.push(arr[i]);
    }

    return m;
}

vector<int> nge(map<int, int> &m, vector<int> &query) {
    int n = query.size();
    vector<int> ans;

    // ======================================================INCOMPLETE
    // ===============================================

    for (auto &val : query) {
        ans.push_back(m[val]);
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

    int m;
    cin >> m;
    vector<int> query;

    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;
        query.push_back(val);
    }

    map<int, int> mp = ngeR(arr);
    vector<int> ans = nge(mp, query);

    for (auto &val : ans) {
        cout << val << " ";
    }

    return 0;
}