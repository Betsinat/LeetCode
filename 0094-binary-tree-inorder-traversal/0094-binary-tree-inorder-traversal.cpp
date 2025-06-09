class Solution {
public:
 void inorderHelper(TreeNode* root , vector<int>& result){
        if(root == nullptr) return;
        inorderHelper(root ->left , result);
        result.push_back(root -> val);
        inorderHelper(root -> right , result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
    vector<int>result;
    inorderHelper(root, result);
    return result;
    
    }
};
