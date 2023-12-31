// 1. You are given a word (may have one character repeat more than once).
// 2. You are given an integer k.
// 2. You are required to generate and print all ways you can select k characters out of the word.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't force you but the intention is to teach a concept. Play in spirit of the question.

#include <bits/stdc++.h>

using namespace std;

void word_k_selection_03(int idx, string str, string ans, int k, map<char, int> &m)
{
    if (idx == str.length())
    {
        if (ans.length() == k)
        {
            cout << ans << endl;
        }

        return;
    }

    int iterationLimit = m[str[idx]];

    for (int i = iterationLimit; i >= 1; i--)
    {
        string charCount = "";
        for (int j = 1; j <= i; j++)
        {
            charCount += str[idx];
        }

        word_k_selection_03(idx + 1, str, ans + charCount, k, m);
    }

    word_k_selection_03(idx + 1, str, ans, k, m);
    return;
}

int main()
{
    string str;
    cin >> str;
    int k;
    cin >> k;

    map<char, int> m;
    string uStr = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (m.find(str[i]) == m.end())
        {
            uStr += str[i];
        }
        m[str[i]]++;
    }

    // cout << uStr << endl;
    word_k_selection_03(0, uStr, "", k, m);

    return 0;
}

// INPUT
// aabbbccdde
// 3

// OUTPUT
// aab
// aac
// aad
// aae
// abb
// abc
// abd
// abe
// acc
// acd
// ace
// add
// ade
// bbb
// bbc
// bbd
// bbe
// bcc
// bcd
// bce
// bdd
// bde
// ccd
// cce
// cdd
// cde
// dde
