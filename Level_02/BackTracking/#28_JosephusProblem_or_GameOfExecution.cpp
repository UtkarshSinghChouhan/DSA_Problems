// 1. You are given two numbers N and K.
// 2. N represents the total number of soldiers standing in a circle having
// position marked from 0 to N-1.
// 3. A cruel king wants to execute them but in a different way.
// 4. He starts executing soldiers from 0th position and proceeds around the
// circle in clockwise direction.
// 5. In each step, k-1 soldiers are skipped and the k-th soldier is executed.
// 6. The elimination proceeds around the circle (which is becoming smaller and
// smaller as the executed soldiers are removed), until only the last soldier
// remains, who is given freedom.
// 7. You have to find the position of that lucky soldier.

// INPUT
// 4
// 2

// OUTPUT
// 0

#include <iostream>
using namespace std;

int gameOfExecution(int n, int k) {

    // The very last solider is freed, thats why we are returning zero (Do a dry
    // run for any input to understand)
    if (n == 1) {
        return 0;
    }

    int ans = gameOfExecution(n - 1, k);

    int originalAns = (ans + k) % n;

    return originalAns;
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << gameOfExecution(n, k);

    return 0;
}