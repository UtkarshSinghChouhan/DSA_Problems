#include <bits/stdc++.h>
using namespace std;
int tp = 0;

void totalPaths(int sr, int sc, int dr, int dc, vector<vector<int>> &visited)
{
    if (sr == dr && sc == dc)
    {
        tp += 1;
        return;
    }
    else if (sr >= dr || sc >= dc || visited[sr][sc] == 1)
    {
        return;
    }
    visited[sr][sc] = 1;
    totalPaths(sr, sc + 1, dr, dc, visited);
    totalPaths(sr + 1, sc, dr, dc, visited);
    visited[sr][sc] = 0;
    return;
}

int main()
{
    int m;
    cin >> m;
    int n;
    cin >> n;
    vector<vector<int>> visited(m, vector<int>(n, 0));
    totalPaths(0, 0, m - 1, n - 1, visited);
    cout << tp << endl;
    return 0;
}