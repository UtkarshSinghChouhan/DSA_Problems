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


void postOrderTraversal(TreeNode* root){
    if(!root) return;


    postOrderTraversal(root->left);
    postOrderTraversal(root->right);

    cout << root->val << " ";

    return;
}

void inOrderTraversal(TreeNode* root){
    if(!root) return;


    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);

    return;
}



// psi - postOrder Starting Index
// pei - postOrder Ending Index
// isi - inOrder Starting Index
// iei - inOrder Ending Index

TreeNode* constructBST(vector<int> postOrder, vector<int> inOrder, int psi, int pei, int isi, int iei){

    if(isi > iei){
        return nullptr;
    }

    int idx = isi;


    while(inOrder[idx] != postOrder[pei]) idx++;

    // Count of Left Sub Tree Elements
    int cntLSE = idx - isi;

    TreeNode* leftSubTree = constructBST(postOrder, inOrder, psi, psi + cntLSE - 1, isi, idx - 1);
    TreeNode* rightSubTree = constructBST(postOrder, inOrder, psi + cntLSE, pei - 1, idx + 1, iei);

    TreeNode* node = new TreeNode(postOrder[pei], leftSubTree, rightSubTree);

    return node;
}


int main(){

    int n; cin >> n;

    vector<int> postOrder;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        postOrder.push_back(val);
    }

    vector<int> inOrder;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        inOrder.push_back(val);
    }

    TreeNode* root = constructBST(postOrder, inOrder, 0, n - 1, 0, n - 1);


    postOrderTraversal(root);

    cout << endl;

    inOrderTraversal(root);


    return 0;
}
