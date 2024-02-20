#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int largestAreaHistogram(vector<int> &arr) {
    int n = arr.size();
    int area = 0;
    stack<int> st;
    vector<int> nseL(n, 0);

    for (int i = 0; i <= n; i++) {
        int val = i == 0 ? 0 : arr[i];

        // pop and calculate area
        while (!st.empty() && arr[st.top()] >= val) {
            int lm = nseL[st.top()];
            int rm = i;
            int ht = arr[st.top()];
            area = max(area, ht * (rm - lm - 1));
            st.pop();
        }

        // answer
        if (st.size() == 0) {
            nseL[i] = -1;
        } else {
            nseL[i] = st.top();
        }

        // push
        st.push(i);
    }

    return area;
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

    int area = largestAreaHistogram(arr);
    cout << area << endl;
    return 0;
}

// INPUT
// 7(n)
// 6
// 2
// 5
// 4
// 5
// 1
// 6

// OUPUT
// 12 (maximum area)

// INPUT
// 8(n)
// 2
// 1
// 5
// 6
// 6
// 6
// 2
// 3

// OUTPUT
// 20 (maximum area)