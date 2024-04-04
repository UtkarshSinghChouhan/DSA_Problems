#include<iostream>
#include<vector>
using namespace std;

// Represents the Node of the Trie
class Node{
    public:

    // children array
    vector<Node*> childs;

    // flag to mark the end
    bool isEnd;

    Node(){
        childs = vector<Node*>(26, nullptr);        //length 26 represents the total number of characters possible
        isEnd = false;
    }
};

class Trie{
    public: 
    Node* root;

    Trie(){
        root = new Node();
    }

    // Insert
    void insert(string &str){
        // Dummy node pointing the root
        Node* curr = root;

        int len = str.length();
        for(int i = 0; i < len; i++){
            char ch = str[i];   //character to be insert
            int idx = ch - 'a'; //index at which character is stored in the "childs" array of the current Node

            // if the charater does-not already exists in the trie
            if(curr->childs[idx] == nullptr){
                // create a new Node to insert in the trie
                Node* newNode = new Node();

                // add newNode to the childs of the current node
                curr->childs[idx] = newNode;
            }

            // move the dummy (curr) pointer to the next Node
            curr = curr->childs[idx];
        }

        // Mark the ending character as "end"
        curr->isEnd = true;

    }

    // Search
    bool search( string &str){
       // Dummy node pointing the root
        Node* curr = root;

        int len = str.length();
        for(int i = 0; i < len; i++){
            char ch = str[i];   //character to be insert
            int idx = ch - 'a'; //index at which character is stored in the "childs" array of the current Node

            // in case of a particular character of the word does not exists in the trie
            if(curr->childs[idx] == nullptr){
                return false;
            }

            // move the curr pointer to the next Node
            curr = curr->childs[idx];
        }

        // return true only if the last character of the word is the acutually ending-Node
        return curr->isEnd;
    }

    // Starts With
    bool startsWith(string &str){
         // Dummy node pointing the root
        Node* curr = root;

        int len = str.length();
        for(int i = 0; i < len; i++){
            char ch = str[i];   //character to be insert
            int idx = ch - 'a'; //index at which character is stored in the "childs" array of the current Node

            // in case of a particular character of the word does not exists in the trie
            if(curr->childs[idx] == nullptr){
                return false;
            }

            // move the curr pointer to the next Node
            curr = curr->childs[idx];
        }

        // after we have successfully traverse all the characters of the given word,
        // it means there exists a ord in the trie start with the given "str"
        return true;
    }

};

int main(){

    int n; cin >> n;
    Trie t;
    
    for(int i = 1; i <= n; i++){
        string operation, value;
        cin >> operation >> value;

        if(operation == "insert"){
           t.insert(value);
           cout << "null" << endl;
        }else if(operation == "search"){
            cout << (t.search(value) ? "true" : "false") << endl;
        }else{
            cout << (t.startsWith(value) ? "true" : "false") << endl;
        }

    }
    return 0;
}