// . You are give a number of boxes (nboxes) and number of identical items
// (ritems).
// 2. You are required to place the items in those boxes and print all such
// configurations possible.

// Items are identical and all of them are named 'i'.
// Note 1 -> Number of boxes is greater than number of items, hence some of the
// boxes may remain
//                    empty.
// Note 2 -> Check out the question video and write the recursive code as it is
// intended without
//                    changing signature. The judge can't force you but intends
//                    you to teach a concept.

#include <iostream>
using namespace std;

// void print_Combinations(int cb, int tb, int cs, int ts, string ans)
// {
//     if (cb > tb)
//     {
//         if (cs == ts)
//         {
//             cout << ans << endl;
//         }

//         return;
//     }
//     print_Combinations(cb + 1, tb, cs + 1, ts, ans + "i");
//     print_Combinations(cb + 1, tb, cs + 0, ts, ans + "-");
//     return;
// }

// tb- total box
// cb - current box
// ti - total item
// asf - answer so far

void combination_01(int tb, int cb, int ti, string asf) {
    if (cb > tb) {
        if (ti == 0) {
            cout << asf << endl;
        }

        return;
    }

    combination_01(tb, cb + 1, ti - 1, asf + "i");
    combination_01(tb, cb + 1, ti, asf + "-");
    return;
}

int main() {
    int n;
    cin >> n;
    int r;
    cin >> r;

    // print_Combinations(1, n, 0, r, "");

    combination_01(n, 1, r, "");

    return 0;
}

// Input
// 5
// 3

// Output
// iii--
// ii-i-
// ii--i
// i-ii-
// i-i-i
// i--ii
// -iii-
// -ii-i
// -i-ii
// --iii