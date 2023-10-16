// 1. You are given a number n, representing the number of stairs in a staircase.
// 2. You are on the 0th step and are required to climb to the top.
// 3. You are given n numbers, where ith element's value represents - till how far from the step you
//      could jump to in a single move.
//      You can of course jump fewer number of steps in the move.
// 4. You are required to print the number of different paths via which you can climb to the top.

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

    vector<int> dp(n + 1, 0);
    dp[n] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= moves[i]; j++)
        {
            dp[i] += dp[(i + j) <= n ? (i + j) : 0];
        }

        cout << i << "->" << dp[i] << endl;
    }

    cout << dp[0] << endl;
    return 0;
}