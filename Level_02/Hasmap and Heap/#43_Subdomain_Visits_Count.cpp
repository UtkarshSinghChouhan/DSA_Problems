#include <iostream>
#include <map>
#include <vector>
using namespace std;

// utility function
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

vector<string> generateSubDomains(vector<string> &words) {
    vector<string> ans;

    int len = words.size();

    for (int i = 0; i < len; i++) {
        string str = "";
        for (int j = i; j < len; j++) {

            if (j != len - 1) {
                str += words[j] + ".";
            } else {
                str += words[j];
            }
        }

        ans.push_back(str);
    }

    return ans;
}

vector<string> subdomainCount(vector<string> &input) {

    vector<string> ans;
    map<string, int> m;

    for (auto &domain : input) {
        vector<string> temp = stringSplit(domain, ' ');
        int visCount = stoi(temp[0]);

        vector<string> words = stringSplit(temp[1], '.');

        vector<string> subDomains = generateSubDomains(words);

        for (auto &subDomain : subDomains) {
            if (m.count(subDomain)) {
                m[subDomain] += visCount;
            } else {
                m[subDomain] = visCount;
            }
        }
    }

    for (auto &[subDomain, visCnt] : m) {
        string str = "";
        str += to_string(visCnt) + " " + subDomain;
        ans.push_back(str);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<string> input;
    for (int i = 0; i < n; i++) {
        string val;
        getline(cin, val);
        input.push_back(val);
    }

    vector<string> ans = subdomainCount(input);

    for (auto &val : ans) {
        cout << val << endl;
    }

    return 0;
}