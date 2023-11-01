// 1. You are given a word (may have one character repeat more than once).
// 2. You are required to generate and print all arrangements of these characters.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't
//                force you but the intention is to teach a concept. Play in spirit of the question.

#include <bits/stdc++.h>

using namespace std;

void permutations_word_02(int idx, string str, vector<char> &boxes, map<char, int> &m)
{
    if (idx == str.length())
    {
        string ans = "";
        for (auto &val : boxes)
        {
            ans += val;
        }

        cout << ans << endl;
        return;
    }

    int lastIdx = m[str[idx]];
    for (int i = lastIdx + 1; i < str.length(); i++)
    {
        if (boxes[i] == '0')
        {
            m[str[idx]] = i;
            boxes[i] = str[idx];
            permutations_word_02(idx + 1, str, boxes, m);
            boxes[i] = '0';
            m[str[idx]] = -1;
        }
    }

    return;
}

int main()
{
    string str;
    cin >> str;

    map<char, int> m;

    for (int i = 0; i < str.length(); i++)
    {
        m[str[i]] = -1;
    }

    // for (auto &it : m)
    // {
    //     cout << it.first << " -> " << it.second << endl;
    // }

    vector<char> boxes(str.length(), '0');
    permutations_word_02(0, str, boxes, m);
    return 0;
}

// INPUT
// aabb

// OUTPUT
// aabb
// abab
// abba
// baab
// baba
// bbaa