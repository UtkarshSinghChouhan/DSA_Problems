#include <iostream>
#include <unordered_map>
using namespace std;

int length(string str, int k) {
    int ans = 0;
    int n = str.length();
    int i = -1, j = -1;
    unordered_map<char, int> m;

    while (true) {
        bool f1 = false, f2 = false;

        while (i < n - 1) {
            f1 = true;
            i++;
            m[str[i]]++;

            if (m.size() == k) {
                int len = i - j;
                ans = max(ans, len);
                cout << ans << endl;
            } else if (m.size() > k) {
                break;
            }
        }

        while (m.size() > k) {
            f2 = true;
            j++;
            m[str[j]]--;
            if (m[str[j]] == 0)
                m.erase(str[j]);

            if (m.size() == k)
                break;
        }

        if (f1 == false && f2 == false)
            break;
    }

    return ans;
}

int main() {
    string str;
    cin >> str;
    int k;
    cin >> k;
    cout << length(str, k);

    return 0;
}