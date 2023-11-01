// 1. You are given a word (may have one character repeat more than once).
// 2. You are given an integer k.
// 2. You are required to generate and print all ways you can select k distinct characters out of the
//      word.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't
//                force you but the intention is to teach a concept. Play in spirit of the question.

#include <bits/stdc++.h>
using namespace std;

void word_K_selection(string str, int idx, string asf, int k)
{

    if (idx == str.length())
    {
        if (asf.length() == k)
        {
            cout << asf << endl;
        }

        return;
    }

    word_K_selection(str, idx + 1, asf + "", k);
    word_K_selection(str, idx + 1, asf + str[idx], k);

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

    word_K_selection(nStr, 0, "", k);
    return 0;
}

// INPUT
// aabbbccdde
// 3

// OUPUT
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
