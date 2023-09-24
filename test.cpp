#include <iostream>
using namespace std;

string maximumOddBinaryNumber(string s)
{
    string maxOdd = "";

    int oneCount = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            oneCount++;
    }

    // cout << oneCount << endl;

    int len = s.length();
    // cout << len << endl;

    int zeroBits = len - oneCount;
    // cout << len - oneCount << endl;

    while (zeroBits > 0)
    {
        maxOdd += '0';
        zeroBits--;
    }

    maxOdd += '1';

    if (oneCount > 1)
    {
        int setBits = oneCount - 1;
        cout << setBits << endl;
        while (setBits > 0)
        {
            maxOdd = '1' + maxOdd;
            setBits--;
        }
    }

    return maxOdd;
}

int main()
{
    string s;
    cin >> s;
    cout << maximumOddBinaryNumber(s);
    return 0;
}