#include <iostream>
#include <unordered_map>

using namespace std;

int count(string &str) {
    int n = str.length();
    int i = -1, j = -1;
    unordered_map<char, int> m;

    int ans = 0;

    while (true) {
        bool f1 = false, f2 = false;
        while (i < n - 1) {
            f1 = true;
            i++;
            m[str[i]]++;
            if (m[str[i]] == 2)
                break;

            int cnt = i - j;
            ans += cnt;
        }

        while (j < i) {
            f2 = true;
            j++;
            m[str[j]]--;
            if (m[str[j]] == 1) {
                int cnt = i - j;
                ans += cnt;
                break;
            }
        }

        if (f1 == false && f2 == false)
            break;
    }

    return ans;
}

int main() {
    string str;
    cin >> str;
    cout << count(str);
    return 0;
}