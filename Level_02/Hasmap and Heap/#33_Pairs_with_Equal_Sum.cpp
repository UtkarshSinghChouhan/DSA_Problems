#include <iostream>
#include <set>
#include <vector>
using namespace std;

void findPairSum(vector<int> &arr) {
    int n = arr.size();
    set<int> s;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if (s.count(sum)) {
                cout << "sum = " << sum << endl;
                cout << "true(" << arr[i] << ", " << arr[j] << ")";
                return;
            }

            s.insert(sum);
        }
    }

    cout << "none" << endl;
    return;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    findPairSum(arr);
    return 0;
}