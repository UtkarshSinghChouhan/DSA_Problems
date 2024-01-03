// 1. You are given a number n, representing the number of stairs in a
// staircase.
// 2. You are on the 0th step and are required to climb to the top.
// 3. You are given n numbers, where ith element's value represents - till how
// far from the step you
//      could jump to in a single move.
//      You can of course jump fewer number of steps in the move.
// 4. You are required to print the number of different paths via which you can
// climb to the top.

// INPUT
// 10
// 3
// 3
// 0
// 2
// 1
// 2
// 4
// 2
// 0
// 0

// OUTPUT
// 5

// INPUT
// 6
// 2
// 3
// 0
// 1
// 2
// 2

// OUTPUT
// 2

#include <bits/stdc++.h>
using namespace std;

int utilsRecursive(vector<int> moves, int idx) {
    if (idx == moves.size()) {
        return 1;
    } else if (moves[idx] == 0) {
        return 0;
    } else if (idx > moves.size()) {
        return 0;
    }

    int totalPaths = 0;
    for (int i = 1; i <= moves[idx]; i++) {
        int pathCnt = utilsRecursive(moves, idx + i);
        totalPaths += pathCnt;
    }

    return totalPaths;
}

int utilsMemo(vector<int> moves, int idx, vector<int> dp) {
    if (idx == moves.size()) {
        return 1;
    } else if (moves[idx] == 0) {
        return 0;
    } else if (idx > moves.size()) {
        return 0;
    } else if (dp[idx] != -1) {
        return dp[idx];
    }

    int tp = 0;

    for (int i = 1; i <= moves[idx]; i++) {
        int val = utilsMemo(moves, idx + i, dp);
        tp += val;
    }

    dp[idx] = tp;

    return tp;
}

int main() {
    int n;
    cin >> n;

    vector<int> moves(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> moves[i];
    }

    // cout << utilsRecursive(moves, 0);

    vector<int> dp(moves.size(), -1);
    cout << utilsMemo(moves, 0, dp);

    // Tabulation
    // vector<int> dp(n + 1, 0);
    // dp[n] = 1;

    // for (int i = n - 1; i >= 0; i--) {
    //     for (int j = 1; j <= moves[i]; j++) {
    //         dp[i] += dp[(i + j) <= n ? (i + j) : 0];
    //     }

    //     // cout << i << "->" << dp[i] << endl;
    // }

    // cout << dp[0] << endl;
    return 0;
}