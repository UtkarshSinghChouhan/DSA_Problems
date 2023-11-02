// 1. You are given a word (may have one character repeat more than once).
// 2. You are given an integer k.
// 3. You are required to generate and print all k length words (of distinct chars) by using chars of the
//      word.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't
//                force you but the intention is to teach a concept. Play in spirit of the question.

#include <bits/stdc++.h>
using namespace std;

void k_length_word_02(int idx, string str, vector<char> &spots, set<char> &used)
{
    if (idx == spots.size())
    {
        string ans = "";
        for (auto &val : spots)
        {
            ans += val;
        }

        cout << ans << endl;
        return;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (used.find(str[i]) == used.end())
        {
            used.insert(str[i]);
            spots[idx] = str[i];
            k_length_word_02(idx + 1, str, spots, used);
            spots[idx] = '0';
            used.erase(str[i]);
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
    set<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        s.insert(str[i]);
    }

    string nStr = "";
    for (auto &val : s)
    {
        nStr += val;
    }

    // cout << nStr << endl;

    vector<char> spots(k, '0');
    set<char> used;
    k_length_word_02(0, nStr, spots, used);

    return 0;
}

// INPUT
// aabbbccdde
// 3

// OUTPUT
// abc
// abd
// abe
// acb
// acd
// ace
// adb
// adc
// ade
// aeb
// aec
// aed
// bac
// bad
// bae
// bca
// bcd
// bce
// bda
// bdc
// bde
// bea
// bec
// bed
// cab
// cad
// cae
// cba
// cbd
// cbe
// cda
// cdb
// cde
// cea
// ceb
// ced
// dab
// dac
// dae
// dba
// dbc
// dbe
// dca
// dcb
// dce
// dea
// deb
// dec
// eab
// eac
// ead
// eba
// ebc
// ebd
// eca
// ecb
// ecd
// eda
// edb
// edc