// 1. You are given a matrix of 0's and 1's.
// 2. You have to find the maximum size square sub-matrix with all 1's.

#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int largestSquareSubmatrixOfOnes(vector<vector<int>> &arr) {
    int n = arr.size(), m = arr[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxSize = INT_MIN;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            // last cell
            if (i == n - 1 && j == m - 1) {
                dp[i][j] = arr[i][j];
            }
            // last row
            else if (i == n - 1) {
                dp[i][j] = arr[i][j];
            }
            // last column
            else if (j == m - 1) {
                dp[i][j] = arr[i][j];
            }
            // rest
            else {
                if (arr[i][j] == 0) {
                    dp[i][j] = 0;
                } else {

                    dp[i][j] =
                        min(dp[i + 1][j + 1], min(dp[i][j + 1], dp[i + 1][j])) +
                        1;
                }
            }
            maxSize = max(maxSize, dp[i][j]);
        }
    }

    return maxSize;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    cout << largestSquareSubmatrixOfOnes(arr);

    return 0;
}

// Input
// 5 6
// 0 1 0 1 0 1
// 1 0 1 0 1 0
// 0 1 1 1 1 0
// 0 0 1 1 1 0
// 1 1 1 1 1 1

// Output
// 3