#include <bits/stdc++.h>
using namespace std;

// Weighted Graph
class Edge
{
public:
    int src;
    int ngb;

    Edge(int src, int ngb)
    {
        this->src = src;
        this->ngb = ngb;
    }
};

void traverse(vector<vector<int>> arr, int i, int j, vector<vector<int>> &visited)
{

    if (i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size() || arr[i][j] == 1 || visited[i][j] == 1)
    {
        return;
    }

    visited[i][j] = 1;

    traverse(arr, i - 1, j, visited);
    traverse(arr, i, j + 1, visited);
    traverse(arr, i + 1, j, visited);
    traverse(arr, i, j - 1, visited);

    return;
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }

        cout << endl;
    }

    vector<vector<int>> visited(n, vector<int>(m, 0));

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] != 1 && visited[i][j] != 1)
            {
                traverse(arr, i, j, visited);
                count++;
            }
        }

        cout << endl;
    }

    cout << count << endl;

    return 0;
}

// 1. You are given a 2d array where 0's represent land and 1's represent water.
//      Assume every cell is linked to it's north, east, west and south cell.
// 2. You are required to find and count the number of islands.

// Input
// 8
// 8
// 0 0 1 1 1 1 1 1
// 0 0 1 1 1 1 1 1
// 1 1 1 1 1 1 1 0
// 1 1 0 0 0 1 1 0
// 1 1 1 1 0 1 1 0
// 1 1 1 1 0 1 1 0
// 1 1 1 1 1 1 1 0
// 1 1 1 1 1 1 1 0

// Output
// 3