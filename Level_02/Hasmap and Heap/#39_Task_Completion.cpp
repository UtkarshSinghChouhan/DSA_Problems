#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void assignTasks(int totalTasks, vector<int> &completedTaks, vector<int> &p1,
                 vector<int> &p2) {
    unordered_set<int> s;
    for (auto &val : completedTaks) {
        s.insert(val);
    }

    int flag = 0;
    for (int i = 1; i <= totalTasks; i++) {
        if (!s.count(i)) {
            if (!flag) {
                p1.push_back(i);
                flag = 1;
            } else if (flag) {
                p2.push_back(i);
                flag = 0;
            }
        }
    }
}

int main() {
    int totalTasks;
    cin >> totalTasks;
    int totalCompletedTasks;
    cin >> totalCompletedTasks;

    vector<int> completedTaks;
    for (int i = 0; i < totalCompletedTasks; i++) {
        int val;
        cin >> val;
        completedTaks.push_back(val);
    }

    vector<int> p1;
    vector<int> p2;

    assignTasks(totalTasks, completedTaks, p1, p2);

    for (auto &val : p1) {
        cout << val << " ";
    }
    cout << endl;

    for (auto &val : p2) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}