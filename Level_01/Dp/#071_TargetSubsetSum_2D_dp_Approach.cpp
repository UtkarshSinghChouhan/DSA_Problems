#include <bits/stdc++.h>
using namespace std;

bool approach_2D(vector<vector<int>> &dp, vector<int> nums)
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

                int colIdx = j - nums[i - 1];
                if (colIdx >= 0 && dp[i - 1][colIdx] == 1)
                {
                    dp[i][j] = dp[i - 1][colIdx];
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

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int tar;
    cin >> tar;

    vector<vector<int>> dp(n + 1, vector<int>(tar + 1, 0));
    bool ans = approach_2D(dp, nums);
    if (ans)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}