// 1. You are given a word (may have one character repeat more than once).
// 2. You are given an integer k.
// 3. You are required to generate and print all k length words by using chars of the word.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't force you but the intention is to teach a concept. Play in spirit of the question.

#include <bits/stdc++.h>
using namespace std;

void k_length_word_03(int idx, int ssf, string str, vector<char> &spots, map<char, int> &m)
{
    if (idx == str.length())
    {
        if (ssf == spots.size())
        {

            string ans = "";
            for (auto &val : spots)
            {
                ans += val;
            }

            cout << ans << endl;
        }
        return;
    }

    int lastIdx = m[str[idx]];

    for (int i = lastIdx + 1; i < str.length(); i++)
    {
        if (spots[i] == '0')
        {
            spots[i] = str[idx];
            m[str[idx]] = i;
            k_length_word_03(idx + 1, ssf + 1, str, spots, m);
            m[str[idx]] = -1;
            spots[i] = '0';
        }
    }

    if (lastIdx == -1)
    {
        k_length_word_03(idx + 1, ssf + 0, str, spots, m);
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
        m[str[i]] = -1;
    }

    vector<char> spots(k, '0');

    k_length_word_03(0, 0, str, spots, m);
    return 0;
}

// INPUT
// aaabb
// 3

// OUPUT
// aaa
// aab
// aba
// baa
// abb
// bab
// bba