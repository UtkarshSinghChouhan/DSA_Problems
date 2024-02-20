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

int maximalRectangle(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();
    vector<int> arr(m, 0);

    for (int i = 0; i < m; i++) {
        arr[i] = mat[0][i];
    }

    int area = largestAreaHistogram(arr);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) {
                arr[j] += 1;
            } else {
                arr[j] = 0;
            }
        }
    }

    for (auto &val : arr) {
        cout << val << " ";
    }

    cout << endl;
    int val = largestAreaHistogram(arr);
    area = max(area, val);
    return area;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
        cout << endl;
    }

    int largestArea = maximalRectangle(mat);
    cout << largestArea << endl;
    return 0;
}
