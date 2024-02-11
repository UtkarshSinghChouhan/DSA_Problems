#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> solution(int x, int y, int bound) {
    // to avoid duplicate combinations which results into the same sum
    set<int> s;

    for (int A = 1; A < bound; A *= x) {
        for (int B = 1; B < bound; B *= y) {
            if (A + B <= bound) {
                s.insert(A + B);
            }

            if (y == 1)
                break;
        }
        if (x == 1)
            break;
    }

    vector<int> ans(s.begin(),
                    s.end()); // syntax to copy elements of the set to vector
    return ans;
}

int main() {
    int x, y, bound;
    cin >> x >> y >> bound;

    vector<int> ans = solution(x, y, bound);

    for (auto &val : ans)
        cout << val << " ";
    return 0;
}