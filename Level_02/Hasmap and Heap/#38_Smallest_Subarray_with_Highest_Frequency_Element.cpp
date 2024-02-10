// Prerequisite, Try to generate a FREQUENCY-MAP and calculate the MAX-FREQUENCY
// and MAX-FREQUENCY-ELEMENT  in a single traversal of the array.(It will help
// in writing the code on your own by looking at the algo.)

#include <iostream>
#include <unordered_map>
#include <utility> //for pair
#include <vector>

using namespace std;

pair<int, int> smallestSubstringAndMostFrequentElement(vector<int> &arr) {
    int n = arr.size();

    // map<element, pair<frequency, firstOccurenceIdx>>
    unordered_map<int, pair<int, int>> m;

    int maxFreq = 0, maxFreqEle = -1, minSubarrLen = 0;

    for (int i = 0; i < n; i++) {
        int val = arr[i];

        // if the array element already exists in the map
        if (m.count(val)) {
            m[val].first++;

        } else {
            m[val] = {1, i};
        }
        int freq = m[val].first;

        // potential-Length = (currentIdx - firstOccurenceIdx) + 1
        int pLen = (i - m[val].second) + 1;

        if (freq > maxFreq) {
            maxFreq = freq;
            maxFreqEle = val;

            minSubarrLen = pLen;
        } else if (freq == maxFreq) {

            if (pLen < minSubarrLen) {

                minSubarrLen = pLen;
                maxFreqEle = val;
            }
        }
    }

    return {maxFreqEle, minSubarrLen};
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

    pair<int, int> p = smallestSubstringAndMostFrequentElement(arr);
    cout << p.first << " " << p.second << endl;

    return 0;
}

// INPUT
// 13
// 1
// 3
// 2
// 4
// 2
// 3
// 4
// 2
// 5
// 6
// 5
// 5
// 7

// OUTPUT
// {5, 4}