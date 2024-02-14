#include <iostream>
#include <limits.h>
#include <map>
#include <stack>
#include <vector>

using namespace std;

class FreqStack {
  public:
    map<int, stack<int>> m;
    map<int, int> freqMap;
    int maxFreq = INT_MIN;
    FreqStack() {}

    int push(int val) {
        freqMap[val]++;
        int key = freqMap[val];

        if (m.count(key)) {
            m[key].push(val);

        } else {
            stack<int> st;
            st.push(val);
            m[key] = st;
        }

        int size = m.size();
        maxFreq = max(maxFreq, size);

        return -1;
    }

    int pop() {
        int returnVal = m[maxFreq].top();
        m[maxFreq].pop();

        int size = m[maxFreq].size();
        if (size == 0) {
            m.erase(maxFreq);
            maxFreq--;
        }

        freqMap[returnVal]--;

        if (freqMap[returnVal] ==
            0) // here if we try to defined a removeFromMap utility function, we
               // need to make it generic because on map is int-vs-stack and the other one is int-vs-int
            freqMap.erase(returnVal);

        return returnVal;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> ans;
    FreqStack obj;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        if (val > 0) {
            int res = obj.push(val);
            ans.push_back(res);
        } else {
            int res = obj.pop();
            ans.push_back(res);
        }
    }

    // displaying the answer
    for (auto &val : ans) {
        cout << val << " ";
    }

    return 0;
}

// -1 -> pop()
// +ve value -> push()