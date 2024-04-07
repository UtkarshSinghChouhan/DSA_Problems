#include<iostream>
#include<vector>
using namespace std;

class Node{
    public: 
    vector<Node*> childs;
    bool isEnd;

    Node(){
        childs = vector<Node*>(26, nullptr);
        isEnd = false;
    }
};

class Trie{
    public: 
    Node* root;
    Trie(){
        root = new Node();
    }

    // insert
    void insert(string &str){
        Node* curr = root;
        int len = str.length();

        for(int i = 0; i < len; i++){
            char ch = str[i];
            int idx = ch - 'a';

            if(curr->childs[idx] == nullptr){
                Node* newNode = new Node();
                curr->childs[idx] = newNode;
            }

            curr = curr->childs[idx];
        }

        curr->isEnd = true;
    }

    // find
    bool find(string &str, int idx, Node* curr){
        if(idx == str.length()){
            return curr->isEnd;
        }

        char ch = str[idx];

        if(ch == '.'){
            for(int i = 0; i < curr->childs.size(); i++){
                if(curr->childs[i] != nullptr){
                    bool res =  find(str, idx + 1, curr->childs[i]);
                    if(res) return true;
                }
            } 
            return false;   
        }else{
           if(curr->childs[ch - 'a'] == nullptr){
                return false;
           }else{
               bool res = find(str, idx + 1, curr->childs[ch - 'a']); 
               return res;
           }  
        }
    }

    // search
    bool search(string &str){
        Node* curr = root;
        return find(str, 0, curr);
    }
};

int main(){
    Trie t;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string s1, s2;
        cin >> s1 >> s2;

        if(s1 == "+"){
            t.insert(s2);
            cout << "null" << endl;
        }else if(s1 == "#"){
            cout << (t.search(s2) == 1 ?  "true" : "false") << endl; 
        }
    }
    return 0;
}