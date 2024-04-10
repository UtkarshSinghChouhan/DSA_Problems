#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    vector<Node *> childs;
    bool isEnd;

    Node()
    {
        childs = vector<Node *>(26, nullptr);
        isEnd = false;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }

    // string split function
    vector<string> splitString(string &str, char delim)
    {
        string s = "";
        vector<string> res;

        for (auto &ch : str)
        {
            if (ch != delim)
            {
                s.push_back(ch);
            }
            else
            {
                res.push_back(s);
                s = "";
            }
        }

        res.push_back(s);

        return res;
    }

    void insert(string &str)
    {

        Node *curr = root;

        int len = str.length();
        for (int i = 0; i < len; i++)
        {
            char ch = str[i];
            int idx = ch - 'a';

            if (curr->childs[idx] == nullptr)
            {

                Node *newNode = new Node();

                curr->childs[idx] = newNode;
            }

            curr = curr->childs[idx];
        }

        curr->isEnd = true;
    }

    // function identifies weather the prefix of hte given word exists in the trie or not
    // And it stores the prefix in the string asf
    bool searchPrefix(Node* root, string &str, int idx, string &asf){
        if(idx == str.length()){

            return false;
        }

        if(root->isEnd){
            return true;
        }

        char ch = str[idx];
        if(root->childs[ch - 'a'] == nullptr){
            return false;
        }else{
            asf.push_back(ch);
            bool val = searchPrefix(root->childs[ch - 'a'], str, idx + 1, asf);
            if(val){
                return true;
            }
            asf.pop_back();
        }

        return false;
    }
};

int main()
{
    Trie t;
    int n;
    cin >> n;
    vector<string> roots;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        cin.ignore();
        roots.push_back(str);
    }

    string sentence;
    getline(cin, sentence);

    // inserting words in the trie
    for(auto &root: roots){
        t.insert(root);
    }

    // spliting the sentence into the words array
    vector<string> words = t.splitString(sentence, ' ');

    string ans = "";

    for(auto &word : words){
        string asf = "";

        bool val = t.searchPrefix(t.root, word, 0, asf);

        if(val){
            ans += asf + " ";
        }else{
            ans += word + " ";
        }
    }
    ans.pop_back();

    cout << ans << endl;

    return 0;
}