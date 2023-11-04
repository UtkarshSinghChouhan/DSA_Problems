// 1. You are given a word (may have one character repeat more than once).
// 2. You are given an integer k.
// 3. You are required to generate and print all ways you can select k characters out of the word.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't force you but the intention is to teach a concept. Play in spirit of the question.

#include <bits/stdc++.h>
using namespace std;

void word_k_selection_04(string asf, string ustr, map<char, int> &m, int lastUsedIndex, int k)
{
    if (asf.length() == k)
    {
        cout << asf << endl;
        return;
    }
    for (int i = lastUsedIndex; i < ustr.length(); i++)
    {
        if (m[ustr[i]] != 0)
        {
            m[ustr[i]] -= 1;
            word_k_selection_04(asf + ustr[i], ustr, m, i, k);
            m[ustr[i]] += 1;
        }
    }
    return;
}

int main()
{
    string str;
    cin >> str;
    int k;
    cin >> k;

    map<char, int> m;
    string ustr = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (m.find(str[i]) == m.end())
        {
            ustr += str[i];
        }

        m[str[i]]++;
    }

    word_k_selection_04("", ustr, m, 0, k);
    return 0;
}

// CONSTRAINTS
//  0 < str.length() < 15
//  0 < k <= str.length()

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