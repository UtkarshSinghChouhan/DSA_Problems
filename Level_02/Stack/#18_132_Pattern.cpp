#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

bool _132patternBruteFore(vector<int> &inputs) {
    int n = inputs.size();

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            if (inputs[i] < inputs[j]) {
                for (int k = j + 1; k < n; k++) {
                    if (inputs[k] > inputs[i] && inputs[k] < inputs[j]) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool _132patternBetterApproach(vector<int> &nums) {
    int nums_i = nums[0];
    int n = nums.size();

    for (int j = 1; j < n - 1; j++) {
        nums_i = min(nums_i, nums[j]);

        if (nums_i < nums[j]) {
            for (int k = j + 1; k < n; k++) {
                if (nums_i < nums[k] && nums[k] < nums[j]) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> inputs;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        inputs.push_back(val);
    }

    // cout << _132patternBruteFore(inputs);
    cout << _132patternBetterApproach(inputs);

    return 0;
}