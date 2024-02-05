#include <iostream>
#include <unordered_map>

using namespace std;

string fraction_to_recurring_decimal(int n, int d) {
    string ans = "";

    int q = n / d;
    int r = n % d;

    ans += to_string(q);

    if (r == 0) {
        return ans;
    } else {
        ans += ".";

        // remainder vs very-first-position(index of the answer-string)
        unordered_map<int, int> m;
        while (r != 0) {
            if (m.count(r)) {

                string fPart = ans.substr(0, m[r]);
                string sPart = ans.substr(m[r]);

                ans = fPart + "(" + sPart + ")";
                return ans;
            }

            m[r] = ans.length();
            r *= 10;

            q = r / d;
            ans += to_string(q);

            r = r % d;
        }
    }

    return ans;
}

int main() {
    int n, d;
    cin >> n >> d;

    cout << fraction_to_recurring_decimal(n, d);
    return 0;
}

// INPUT-1
// 428
// 125

// OUTPUT-1
// 3.424

// INPUT-1
// 8
// 4

// OUTPUT-1
// 2

// INPUT-1
// 37
// 2

// OUTPUT-1
// 18.5

// INPUT-1
// 14
// 3

// OUTPUT-1
// 4.(6)

// INPUT-1
// 47
// 18

// OUTPUT-1
// 2.6(1)

// INPUT-1
// 93
// 7

// OUTPUT-1
// 13.(285714)