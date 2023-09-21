#include <bits/stdc++.h>
using namespace std;

int print(map<char, set<char>> tree, char root){
    int s = 0;

    for(char child : tree[root]){
        int cs = print(tree, child);
        s += cs;
    }

    cout << root << " " << s << endl;
    return s + 1;
}

void findCount(map<char, char> m){
    char root;
    map<char, set<char>> tree;

    for(auto it : m){
        // it.first -> employee
        // it.second -> manager

        if(it.first == it.second){
            root = it.second;
        }else{
            if(tree.find(it.second) != tree.end()){
                tree[it.second].insert(it.first);
            }else{
                set<char> s;
                s.insert(it.first);
                tree[it.second] = s;
            }
        }
    }

    int ans = print(tree, root);
}

int main()
{
    
    int n; cin >> n;
    map <char, char> m;
    
    
    for(int i = 0; i < n; i++){
        char emp, man;
        cin >> emp >> man;
        
        m[emp] = man;
    }
    
    // for(auto it : m){
    //     cout << it.first << "->" << it.second << endl;
    // }
    
    findCount(m);
    
    return 0;
}

// Number Of Employees Under Every Manager

// 1. You are given number N and 2*N number of strings that contains mapping of the employee and his manager.
// 2. An employee directly reports to only one manager. 
// 3. All managers are employees but the reverse is not true.
// 4. An employee reporting to himself is the CEO of the company.
// 5. You have to find the number of employees under each manager in the hierarchy not just their direct reports.

// Input
// 6
// A C
// B C
// C F
// D E
// E F
// F F

// Output
// A 0
// B 0
// C 2
// D 0
// E 1
// F 5
