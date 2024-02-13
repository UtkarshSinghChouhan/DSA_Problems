#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Euclidean algorithm - Finding HCF via the Long Division Method
int gcd(int dividend, int divisor) {
    if (divisor == 0) {
        return dividend;
    }

    return gcd(divisor, dividend % divisor);
}

bool check(vector<int> &deck) {
    map<int, int> m;

    // frequency map
    for (auto &val : deck) {
        m[val]++;
    }

    int ans = 0;
    for (auto &[key, val] : m) {
        ans = gcd(ans, val);
    }

    if (ans > 1) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> deck;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        deck.push_back(val);
    }

    cout << check(deck);

    return 0;
}

// INPUT
// 10
// 2
// 2
// 2
// 2
// 4
// 4
// 4
// 4
// 4
// 4

// OUTPUT
// TRUE