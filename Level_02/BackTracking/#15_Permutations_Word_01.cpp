// 1. You are given a word (may have one character repeat more than once).
// 2. You are required to generate and print all arrangements of these characters.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't
//                force you but the intention is to teach a concept. Play in spirit of the question.

#include <bits/stdc++.h>
using namespace std;

void permutations_word_01(map<char, int> &m, string asf, int len)
{
    if (asf.length() == len)
    {
        cout << asf << endl;
        return;
    }
    for (auto &it : m)
    {
        if (it.second != 0)
        {
            it.second -= 1;
            permutations_word_01(m, asf + it.first, len);
            it.second += 1;
        }
    }
}

int main()
{
    string str;
    cin >> str;

    map<char, int> m;

    for (int i = 0; i < str.length(); i++)
    {
        m[str[i]]++;
    }

    // printing to check weatger we have created the frequency map successfully
    // for (auto &it : m)
    // {
    //     cout << it.first << " -> " << it.second << endl;
    // }

    permutations_word_01(m, "", str.length());

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
