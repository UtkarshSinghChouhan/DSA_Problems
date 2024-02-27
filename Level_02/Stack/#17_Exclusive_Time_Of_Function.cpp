#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Element {

  public:
    int id;
    int startTime;
    int childExeTime;
    Element(int id, int startTime, int childExeTime) {
        this->id = id;
        this->startTime = startTime;
        this->childExeTime = childExeTime;
    }
};

vector<string> stringSplit(string str, char delim) {
    vector<string> ans;
    string s = "";

    for (auto &ch : str) {
        if (ch != delim) {
            s += ch;
        } else {
            ans.push_back(s);
            s = "";
        }
    }
    ans.push_back(s);

    return ans;
}

vector<int> exclusiveTimeOfFunction(vector<string> inputs, int n) {
    vector<int> ans(n, 0);
    stack<Element> st;

    for (string &str : inputs) {
        vector<string> splits = stringSplit(str, ':');
        int id = stoi(splits[0]);
        string start_end = splits[1];
        int start_end_Time = stoi(splits[2]);

        if (start_end == "start") {
            Element e(id, start_end_Time, 0);
            st.push(e);
        } else if (start_end == "end") {
            // remove the stack top element and calculate its effective
            // execution time
            Element e = st.top();
            st.pop();
            int interval = ((start_end_Time - e.startTime) + 1);
            int exeTime = interval - e.childExeTime;
            ans[id] += exeTime;

            // Updating the child execution time in the stack top element;
            if (!st.empty()) {
                st.top().childExeTime += interval;
            }
        }
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> input;
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        input.push_back(str);
    }

    vector<int> ans = exclusiveTimeOfFunction(input, n);

    for (auto &val : ans) {
        cout << val << " ";
    }
    return 0;
}