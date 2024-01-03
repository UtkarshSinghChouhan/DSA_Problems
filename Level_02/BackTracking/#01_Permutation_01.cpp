// 1. You are give a number of boxes (n-boxes) and number of NON-IDENTICAL items
// (r-items).
// 2. You are required to place the items in those boxes and print all such
// configurations possible.

// Items are numbered from 1 to ritems.
// Note 1 -> Number of boxes is greater than number of items, hence some of the
// boxes may remain empty. Note 2 -> Check out the question video and write the
// recursive code as it is intended without changing signature. The judge can't
//                    force you but intends you to teach a concept.

#include <bits/stdc++.h>
using namespace std;

void permutation_01(vector<int> boxes, int ci, int ti) {
    if (ci > ti) {
        for (auto val : boxes) {
            cout << val << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < boxes.size(); i++) {
        if (boxes[i] == 0) {
            boxes[i] = ci;
            permutation_01(boxes, ci + 1, ti);
            boxes[i] = 0;
        }
    }

    return;
}

int main() {

    int n;
    cin >> n;
    int r;
    cin >> r;

    vector<int> boxes(n, 0);

    permutation_01(boxes, 1, r);

    return 0;
}