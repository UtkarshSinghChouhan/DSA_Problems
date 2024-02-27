#include <iostream>
#include <stack>
#include <utility>

using namespace std;

class Solution {
  public:
    stack<pair<int, int>> st;
    int idx = -1;
    Solution() {}

    int next(int val) {
        while (!st.empty() && st.top().first <= val) {
            st.pop();
        }

        int topIdx = st.empty() ? -1 : st.top().second;
        int curIdx = idx + 1;
        int count = curIdx - topIdx;
        st.push({val, curIdx});
        idx++;

        return count;
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        cout << s.next(val) << " ";
    }
    return 0;
}