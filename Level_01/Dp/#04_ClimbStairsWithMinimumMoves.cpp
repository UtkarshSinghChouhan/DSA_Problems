// 1. You are given a number n, representing the number of stairs in a staircase.
// 2. You are on the 0th step and are required to climb to the top.
// 3. You are given n numbers, where ith element's value represents - till how far from the step you
//      could jump to in a single move.  You can of-course jump fewer number of steps in the move.
// 4. You are required to print the number of minimum moves in which you can reach the top of
//      staircase.
// Note -> If there is no path through the staircase print null.

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
// 4

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> moves(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> moves[i];
    }

    vector<int> dp(n + 1, -1);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int minVal = INT_MAX;

        for (int j = 1; j <= moves[i] && (i + j) <= n; j++)
        {
            if (dp[i + j] == -1)
            {
                continue;
            }
            minVal = min(minVal, dp[i + j]);
        }

        if (moves[i] > 0 && minVal != INT_MAX)
        {
            dp[i] = minVal + 1;
        }
        cout << i << "->" << dp[i] << endl;
    }

    cout << dp[0] << endl;

    return 0;
}