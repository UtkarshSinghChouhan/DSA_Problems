// 1. You are given a word (may have one character repeat more than once).
// 2. You are given an integer k.
// 3. You are required to generate and print all k length words (of distinct chars) by using chars of the
//      word.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't
//                force you but the intention is to teach a concept. Play in spirit of the question.

#include <bits/stdc++.h>
using namespace std;

void k_length_word_01(int idx, int ssf, string str, vector<char> &spots)
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

    for (int i = 0; i < spots.size(); i++)
    {
        if (spots[i] == '0')
        {
            spots[i] = str[idx];
            k_length_word_01(idx + 1, ssf + 1, str, spots);
            spots[i] = '0';
        }
    }
    k_length_word_01(idx + 1, ssf + 0, str, spots);

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
    k_length_word_01(0, 0, nStr, spots);

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
// adb
// aeb
// acd
// ace
// adc
// aec
// ade
// aed
// bac
// bad
// bae
// cab
// dab
// eab
// cad
// cae
// dac
// eac
// dae
// ead
// bca
// bda
// bea
// cba
// dba
// eba
// cda
// cea
// dca
// eca
// dea
// eda
// bcd
// bce
// bdc
// bec
// bde
// bed
// cbd
// cbe
// dbc
// ebc
// dbe
// ebd
// cdb
// ceb
// dcb
// ecb
// deb
// edb
// cde
// ced
// dce
// ecd
// dec
// edc