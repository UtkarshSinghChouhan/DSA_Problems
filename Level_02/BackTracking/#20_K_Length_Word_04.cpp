// 1. You are given a word (may have one character repeat more than once).
// 2. You are given an integer k.
// 3. You are required to generate and print all k length words by using chars of the word.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't force you but the intention is to teach a concept. Play in spirit of the question.

#include <bits/stdc++.h>
using namespace std;

void k_length_word_04(string asf, map<char, int> &m, int k)
{
    if (asf.length() == k)
    {
        cout << asf << endl;
        return;
    }
    for (auto &it : m)
    {
        if (it.second != 0)
        {
            it.second -= 1;
            k_length_word_04(asf + it.first, m, k);
            it.second += 1;
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

    // vector<char> spots(k, '0');
    k_length_word_04("", m, k);
    return 0;
}

// INPUT
// aaabb
// 3

// OUTPUT
// aaa
// aab
// aba
// abb
// baa
// bab
// bba
