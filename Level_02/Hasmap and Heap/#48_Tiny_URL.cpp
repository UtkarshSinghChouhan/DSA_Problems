#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
  public:
    map<string, string> m;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = "";

        while (true) {
            shortUrl += char(rand() % 100);

            if (!m.count(shortUrl)) {
                break;
            }
        }

        m[shortUrl] = longUrl;

        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) { return m[shortUrl]; }
};

int main() {
    Solution s;
    string longUrl;
    cin >> longUrl;

    string encodedStr = s.encode(longUrl);

    cout << "encoded Str -> " << encodedStr << endl;
    string decodedUrl = s.decode(encodedStr);
    cout << "decoded Str -> " << decodedUrl << endl;
    if (longUrl == decodedUrl) {
        cout << "answer is correct";
    } else {

        cout << "wrong answer";
    }

    return 0;
}