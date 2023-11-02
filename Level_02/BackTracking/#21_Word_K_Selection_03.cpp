// 1. You are given a word (may have one character repeat more than once).
// 2. You are given an integer k.
// 2. You are required to generate and print all ways you can select k characters out of the word.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't force you but the intention is to teach a concept. Play in spirit of the question.

#include <bits/stdc++.h>

using namespace std;

void word_k_selection_03(string ans, int k, map<char, int> &m)
{
    if (ans.length() == k)
    {
        cout << ans << endl;
        return;
    }

    word_k_selection_03(ans, k, m);

    for (auto &it : m)
    {

        for (int i = 0; i < it.second; i++)
        {
            string str = "";
            for (int j = 0; j <= i; j++)
            {
                str += it.first;
            }
            word_k_selection_03(ans + str, k, m);
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
    for (int i = 0; i < str.length(); i++)
    {
        m[str[i]]++;
    }

    word_k_selection_03("", k, m);

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
