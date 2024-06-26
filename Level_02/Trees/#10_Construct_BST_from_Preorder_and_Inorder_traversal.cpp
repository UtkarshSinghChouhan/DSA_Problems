#include<iostream>
#include<vector>

using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }

    TreeNode(int val, TreeNode* left, TreeNode* right){
        this->val = val;
        this->left = left;
        this->right = right;
    }
};


void preOrderTraversal(TreeNode* root){
    if(!root) return;

    cout << root->val << " ";

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

    return;
}

void inOrderTraversal(TreeNode* root){
    if(!root) return;


    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);

    return;
}



// psi - preOrder Starting Index
// pei - PreOrder Ending Index
// isi - inOrder Starting Index
// iei - inOrder Ending Index

TreeNode* constructBST(vector<int> preOrder, vector<int> inOrder, int psi, int pei, int isi, int iei){

    if(isi > iei){
        return nullptr;
    }

    int idx = isi;


    while(inOrder[idx] != preOrder[psi]) idx++;

    // Count of Left Sub Tree Elements
    int cntLSE = idx - isi;

    TreeNode* leftSubTree = constructBST(preOrder, inOrder, psi + 1, psi + cntLSE, isi, idx - 1);
    TreeNode* rightSubTree = constructBST(preOrder, inOrder, psi + cntLSE + 1, pei, idx + 1, iei);

    TreeNode* node = new TreeNode(preOrder[psi], leftSubTree, rightSubTree);

    return node;
}


int main(){

    int n; cin >> n;

    vector<int> preOrder;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        preOrder.push_back(val);
    }

    vector<int> inOrder;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        inOrder.push_back(val);
    }

    TreeNode* root = constructBST(preOrder, inOrder, 0, n - 1, 0, n - 1);


    preOrderTraversal(root);

    cout << endl;

    inOrderTraversal(root);


    return 0;
}
