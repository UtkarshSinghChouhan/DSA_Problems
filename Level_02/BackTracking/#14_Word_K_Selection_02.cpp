// 1. You are given a word (may have one character repeat more than once).
// 2. You are given an integer k.
// 3. You are required to generate and print all k length words (of distinct chars) by using chars of the
//      word.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't
//                force you but the intention is to teach a concept. Play in spirit of the question.

#include <bits/stdc++.h>
using namespace std;

void word_K_selection(string str, int lp, string asf, int k)
{
    if (asf.length() == k)
    {
        cout << asf << endl;
        return;
    }
    for (int i = lp + 1; i < str.length(); i++)
    {
        word_K_selection(str, i, asf + str[i], k);
    }
    return;
}

int main()
{
    string str;
    cin >> str;
    int k;
    cin >> k;
    set<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        s.insert(str[i]);
    }

    string nStr;
    for (auto &val : s)
    {
        nStr += val;
    }

    // cout << nStr << endl;

    word_K_selection(nStr, -1, "", k);
    return 0;
}

// INPUT
// aabbbccdde
// 3

// OUTPUT
// abc
// abd
// abe
// acd
// ace
// ade
// bcd
// bce
// bde
// cde