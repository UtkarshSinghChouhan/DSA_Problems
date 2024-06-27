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


void preorderTraversal(TreeNode* root){
    if(!root) return;

    cout << root->val << " ";

    preorderTraversal(root->left);
    preorderTraversal(root->right);

    return;
}

void postorderTraversal(TreeNode* root){
    if(!root) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);

    cout << root->val << " ";

    return;
}


TreeNode* constructBT(vector<int> &preOrder, vector<int> &postOrder, int presi, int preei, int postsi, int postei){

    //Dry un the Test Case 2 for understanding below base check
    if(presi > preei){
        return nullptr;
    }

    TreeNode* node = new TreeNode(preOrder[presi]);

    if(presi == preei){
        return node;
    }



    int idx = postsi;

    while(postOrder[idx] != preOrder[presi + 1]) idx++;

    // count of left Subtree Elements
    int cntLSE = idx - postsi + 1;

    node->left = constructBT(preOrder, postOrder, presi + 1, presi + cntLSE, postsi, idx);
    node->right = constructBT(preOrder, postOrder, presi + cntLSE + 1, preei, idx + 1, postei);

    return node;

}


int main(){

    int n; cin >> n;

    vector<int> preOrder;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        preOrder.push_back(val);
    }

    vector<int> postOrder;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        postOrder.push_back(val);
    }

    TreeNode* root = constructBT(preOrder, postOrder, 0, n-1, 0, n-1);


    //verify the constructed Tree by Traversing the Tree in preorder and postorder fashion.
    preorderTraversal(root);
    cout << endl;
    postorderTraversal(root);

    return 0;
}
