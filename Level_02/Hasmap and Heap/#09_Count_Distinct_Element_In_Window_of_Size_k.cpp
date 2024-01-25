#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> countDistinct(vector<int> &arr, int &k) {
    int size = arr.size();

    vector<int> ans;
    unordered_map<int, int> m;

    // Initially acquiring elements
    int i = 0, j = -1;
    while (i <= k - 2) {
        m[arr[i]]++;
        i++;
    }

    i--;

    while (i < size - 1) {
        // Acquire
        i++;
        m[arr[i]]++;

        // work
        ans.push_back(m.size());

        // Release
        j++;
        int fre = m[arr[j]];
        if (fre == 1)
            m.erase(arr[j]);
        else
            m[arr[j]]--;
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cin >> k;

    // cout << k << endl;

    for (auto &val : countDistinct(arr, k)) {
        cout << val << " ";
    }

    return 0;
}