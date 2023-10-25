// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers, representing elements of 2d array a, which represents a maze.
// 4. You are standing in top-left cell and are required to move to bottom-right cell.
// 5. You are allowed to move 1 cell right (h move) or 1 cell down (v move) in 1 motion.
// 6. Each cell has a value that will have to be paid to enter that cell (even for the top-left and bottom-
//      right cell).
// 7. You are required to traverse through the matrix and print the cost of path which is least costly.

// INPUT
// 6
// 6
// 0 1 4 2 8 2
// 4 3 6 5 0 4
// 1 2 4 1 4 6
// 2 0 7 3 2 2
// 3 1 5 9 2 4
// 2 7 0 8 5 1

// OUTPUT
// 23

#include <bits/stdc++.h>
using namespace std;

// void levelAndOption(vector<vector<int>> grid, int sr, int sc, int dr, int dc, int minCost)
// {
//     if (sr == dr && sc == dc)
//     {
//         cout << minCost << endl;
//         return;
//     }

//     if (sr < dr && sc < dc && grid[sr][sc + 1] <= grid[sr + 1][sc])
//     {
//         levelAndOption(grid, sr, sc + 1, dr, dc, minCost + grid[sr][sc + 1]);
//     }

//     if ()
//     {
//         levelAndOption(grid, sr + 1, sc, dr, dc, minCost + grid[sr + 1][sc]);
//     }

//     return;
// }

// int expectionAndFaith(vector<vector<int>> grid, int dr, int dc)
// {

//     int ans1 = expectionAndFaith(grid, dr, dc);
//     int ans2 = expectionAndFaith(grid, dr, dc);
//     int ans = min(ans1, ans2);
//     grid[dr][dc]  = ans;
//     return ans;
// }

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));
    // Level and option approach
    // expectionAndFaith(grid, n - 1, m - 1);

    // Tabulation Approach
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     for (int j = m - 1; j >= 0; j--)
    //     {
    //         // last celll
    //         if (i == n - 1 && j == m - 1)
    //         {
    //             dp[i][j] = grid[i][j];
    //         }

    //         // last row
    //         else if (i == n - 1)
    //         {
    //             dp[i][j] = dp[i][j + 1] + grid[i][j];
    //         }

    //         // last column
    //         else if (j == m - 1)
    //         {
    //             dp[i][j] = dp[i + 1][j] + grid[i][j];
    //         }

    //         else
    //         {
    //             if (dp[i][j + 1] <= dp[i + 1][j])
    //             {

    //                 dp[i][j] = dp[i][j + 1] + grid[i][j];
    //             }
    //             else
    //             {
    //                 dp[i][j] = dp[i + 1][j] + grid[i][j];
    //             }
    //         }

    //         cout << dp[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    // cout << dp[0][0];

    return 0;
}