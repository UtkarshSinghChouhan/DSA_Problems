#include <bits/stdc++.h>
using namespace std;

void floodFill(vector<vector<int>> mat, int sr, int sc, vector<vector<int>> &visited, string psf)
{
    if (sr == mat.size() - 1 && sc == mat[0].size() - 1)
    {
        cout << psf << endl;
        return;
    }
    else if (sr < 0 || sc < 0 || sr >= mat.size() || sc >= mat[0].size() || mat[sr][sc] == 1 || visited[sr][sc] == 1)
    {
        return;
    }

    visited[sr][sc] = 1;

    floodFill(mat, sr - 1, sc, visited, psf + 't');
    floodFill(mat, sr, sc + 1, visited, psf + 'r');
    floodFill(mat, sr + 1, sc, visited, psf + 'd');
    floodFill(mat, sr, sc - 1, visited, psf + 'l');

    visited[sr][sc] = 0;

    return;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    // visited array marked unvisited in every cell
    vector<vector<int>> visited(n, vector<int>(m, 0));

    floodFill(mat, 0, 0, visited, "");

    return 0;
}

// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers, representing elements of 2d array a. The numbers can be 1 or 0 only.
// 4. You are standing in the top-left corner and have to reach the bottom-right corner.
// Only four moves are allowed 't' (1-step up), 'l' (1-step left), 'd' (1-step down) 'r' (1-step right). You can only move to cells which have 0 value in them. You can't move out of the boundaries or in the cells which have value 1 in them (1 means obstacle)
// 5. Complete the body of floodfill function - without changing signature - to print all paths that can be used to move from top-left to bottom-right.

// Note1 -> Please check the sample input and output for details
// Note2 -> If all four moves are available make moves in the order 't', 'l', 'd' and 'r'

// Test Cases

// Input
// 3 3
// 0 0 0
// 1 0 1
// 0 0 0

// Output
// rddr

// Input
// 6 7
// 0 1 0 0 0 0 0
// 0 1 0 1 1 1 0
// 0 0 0 0 0 0 0
// 1 0 1 1 0 1 1
// 1 0 1 1 0 1 1
// 1 0 0 0 0 0 0

// Output
// ddrrttrrrrddlldddrr
// ddrrrrdddrr
// ddrdddrrrrr