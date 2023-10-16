// 1. You are given a number n, representing the number of stairs in a staircase.
// 2. You are on the 0th step and are required to climb to the top.
// 3. In one move, you are allowed to climb 1, 2 or 3 stairs.
// 4. You are required to print the number of different paths via which you can climb to the top.

// INPUT N = 4
// OUTPUT total number of paths = 7

#include <bits/stdc++.h>
using namespace std;

int climbStairs(int cs, int ts)
{

    if (cs == ts)
    {
        return 1;
    }
    else if (cs > ts)
    {
        return 0;
    }

    int csp1 = climbStairs(cs + 1, ts);
    int csp2 = climbStairs(cs + 2, ts);
    int csp3 = climbStairs(cs + 3, ts);

    int tp = csp1 + csp2 + csp3;

    return tp;
}

// Memoized method
int climbStairsMemo(int cs, int ts, vector<int> &dp)
{
    if (cs == ts)
    {
        return 1;
    }
    else if (cs > ts)
    {
        return 0;
    }

    if (dp[cs] != 0)
    {
        return dp[cs];
    }

    int csp1 = climbStairsMemo(cs + 1, ts, dp);
    int csp2 = climbStairsMemo(cs + 2, ts, dp);
    int csp3 = climbStairsMemo(cs + 3, ts, dp);

    int tp = csp1 + csp2 + csp3;
    dp[cs] = tp;

    return tp;
}

int main()
{

    int n;
    cin >> n;

    // Simple Recursive Code
    // cout << climbStairs(0, n);

    // Memoization method
    vector<int> dp(n + 1, 0);
    // cout << climbStairsMemo(0, n, dp);

    // Tabulation method
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = dp[i + 1] + dp[(i + 2) <= n ? (i + 2) : 0] + dp[(i + 3) <= n ? (i + 3) : 0];
        cout << i << "->" << dp[i] << endl;
    }

    cout << dp[0];

    return 0;
}