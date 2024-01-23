// 1. You are given a number.
// 2. You have to print all the numbers from 1 to n in lexicographical order.

// INPUT
// 14

// OUTPUT
// 1
// 10
// 11
// 12
// 13
// 14
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9

#include <iostream>
using namespace std;

void dfs(int n, int idx) {
    if (idx > n) {
        return;
    }

    cout << idx << endl;

    for (int i = 0; i <= 9; i++) {
        dfs(n, idx * 10 + i);
    }

    return;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= 9; i++) {
        dfs(n, i);
    }

    return 0;
}
