// 1. You are given a number n, representing the count of coins.
// 2. You are given n numbers, representing the denominations of n coins.
// 3. You are given a number "amt".
// 4. You are required to calculate and print the number of combinations of the n coins using which the
//      amount "amt" can be paid.

// Note1 -> You have an infinite supply of each coin denomination i.e. same coin denomination can be
//                   used for many installments in payment of "amt"
// Note2 -> You are required to find the count of combinations and not permutations i.e.
//                   2 + 2 + 3 = 7 and 2 + 3 + 2 = 7 and 3 + 2 + 2 = 7 are different permutations of same
//                   combination. You should treat them as 1 and not 3.

#include <bits/stdc++.h>
using namespace std;

// This approach is similar to Target_Subset_sum 2D dp approach
int dp_2D(vector<vector<int>> dp, vector<int> coins)
{
    int n = dp.size(), m = dp[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else if (i == 0)
            {
                dp[i][j] = 0;
            }
            else if (j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
                int colIdx = j - coins[i - 1];
                if (colIdx >= 0)
                {
                    dp[i][j] += dp[i][colIdx];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dp[i][j] << " ";
        }

        cout << endl;
    }

    return dp[n - 1][m - 1];
}

// 1D-Approach
int dp_1D(vector<int> dp, vector<int> coins)
{
    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = coins[i]; j < dp.size(); j++)
        {
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[dp.size() - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> coins(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    int tar;
    cin >> tar;

    vector<vector<int>> dp(n + 1, vector<int>(tar + 1, 0));

    // cout << dp_2D(dp, coins);

    vector<int> dp_oneD(tar + 1, 0);
    dp_oneD[0] = 1;
    cout << dp_1D(dp_oneD, coins);

    return 0;
}

// CONSTRAINT
// 1 <= n <= 30
// 0 <= n1, n2, .. n elements <= 20
// 0 <= tar <= 50

// INPUT
// 4
// 2
// 3
// 5
// 6
// 7

// OUTPUT
// 2