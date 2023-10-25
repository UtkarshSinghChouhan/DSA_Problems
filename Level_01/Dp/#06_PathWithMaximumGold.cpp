// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers, representing elements of 2d array a, which represents a gold mine.
// 4. You are standing in front of left wall and are supposed to dig to the right wall. You can start from
//      any row in the left wall.
// 5. You are allowed to move 1 cell right-up (d1), 1 cell right (d2) or 1 cell right-down(d3).
// 6. Each cell has a value that is the amount of gold available in the cell.
// 7. You are required to identify the maximum amount of gold that can be dug out from the mine.

#include <bits/stdc++.h>
using namespace std;
int maxAmnt = INT_MIN;

// Levels(each level repesent a particular cell) and Option(each cell will always have three options)
void travelAndChange(vector<vector<int>> goldMine, int i, int j, int gsf)
{
    // BASE SMART
    if (j == goldMine[0].size())
    {
        if (gsf > maxAmnt)
        {
            maxAmnt = gsf;
        }

        return;
    }
    else if (i < 0 || i == goldMine.size())
    {
        return;
    }

    // CALL DUMB
    travelAndChange(goldMine, i - 1, j + 1, gsf + goldMine[i - 1][j + 1]);
    cout << "cat" << endl;
    travelAndChange(goldMine, i, j + 1, gsf + goldMine[i][j + 1]);
    travelAndChange(goldMine, i + 1, j + 1, gsf + goldMine[i + 1][j + 1]);
    return;
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<vector<int>> goldMine(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> goldMine[i][j];
        }
    }

    // for (int i = 0, j = 0; i < n; i++)
    // {
    //     cout << "orange" << endl;
    //     travelAndChange(goldMine, i, j, 0);
    //     cout << "mango" << endl;
    // }

    // cout << maxAmnt << endl;

    // Tabulation
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[n - 1][m - 1] = goldMine[n - 1][m - 1];

    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (j == m - 1)
            {
                dp[i][j] = goldMine[i][j];
            }
            else if (i == n - 1)
            {
                dp[i][j] = goldMine[i][j] + max(dp[i - 1][j + 1], dp[i][j + 1]);
            }
            else if (i == 0)
            {
                dp[i][j] = goldMine[i][j] + max(dp[i + 1][j + 1], dp[i][j + 1]);
            }
            else
            {

                dp[i][j] = goldMine[i][j] + max(max(dp[i - 1][j + 1], dp[i][j + 1]), dp[i + 1][j + 1]);
            }
        }
    }

    for (int i = 0, j = 0; i < n; i++)
    {
        if (dp[i][j] > maxAmnt)
        {
            maxAmnt = dp[i][j];
        }
    }

    cout << maxAmnt;

    return 0;
}