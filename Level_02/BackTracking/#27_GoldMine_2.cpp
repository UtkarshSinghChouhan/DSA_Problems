// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers, representing elements of 2d array a, which
// represents a gold mine.
// 4. You are allowed to take one step left, right, up or down from your current
// position.
// 5. You can't visit a cell with 0 gold and the same cell more than once.
// 6. Each cell has a value that is the amount of gold available in the cell.
// 7. You are required to identify the maximum amount of gold that can be dug
// out from the mine if
//      you start and stop collecting gold from any position in the grid that
//      has some gold.

// Note -> Check out the question video and write the recursive code as it is
// intended without
//                changing signature. The judge can't force you but intends you
//                to teach a concept.

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
// 120

#include <iostream>
#include <limits>
#include <vector>
using namespace std;

void travelandFill(vector<vector<int>> &grid, vector<vector<int>> &vis,
                   vector<int> &bag, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
        grid[i][j] == 0 || vis[i][j] == 1) {
        return;
    }

    vis[i][j] = 1;
    bag.push_back(grid[i][j]);
    travelandFill(grid, vis, bag, i - 1, j);
    travelandFill(grid, vis, bag, i, j + 1);
    travelandFill(grid, vis, bag, i + 1, j);
    travelandFill(grid, vis, bag, i, j - 1);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));

    // taking input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int maxGold = INT8_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != 0 && vis[i][j] != 1) {
                vector<int> bag;

                travelandFill(grid, vis, bag, i, j);

                int sum = 0;
                for (auto &val : bag) {
                    sum += val;
                }

                maxGold = max(maxGold, sum);
            }
        }
    }

    cout << maxGold;

    return 0;
}