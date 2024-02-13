#include <iostream>
#include <map>
#include <vector>
using namespace std;

int countBrickCrossing(vector<vector<int>> &wall) {
    // x-coorodinate vs split-count
    map<int, int> m;

    for (auto &row : wall) {
        int scsf = 0; // split-count-so-far
        int n = row.size();

        for (int i = 0; i < n - 1; i++) {
            scsf += row[i];

            m[scsf]++;
        }
    }

    int maxSplitCnt = 0;
    for (auto &[key, val] : m) {
        maxSplitCnt = max(maxSplitCnt, val);
    }

    cout << maxSplitCnt << endl;

    int brickCrossingCount = wall.size() - maxSplitCnt;

    return brickCrossingCount;
}

int main() {
    int n;
    cin >> n; // represents the wall length
    vector<vector<int>> wall;

    for (int i = 0; i < n; i++) {
        vector<int> row;
        int rowLen;
        cin >> rowLen;

        for (int j = 0; j < rowLen; j++) {
            int brick;
            cin >> brick;
            row.push_back(brick);
        }

        wall.push_back(row);
    }

    // for (auto &row : wall) {
    //     for (auto &val : row) {
    //         cout << val << " ";
    //     }

    //     cout << endl;
    // }

    cout << countBrickCrossing(wall);

    return 0;
}