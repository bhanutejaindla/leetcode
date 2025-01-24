/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool validbst(TreeNode* root,long long mini,long long maxi)
    {
        if(!root) return true;
       if(root->val <=mini || root->val>=maxi) return false;
       return validbst(root->left,mini,root->val) && validbst(root->right,root->val,maxi);

    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        long long mini=LLONG_MIN;
        long long maxi=LLONG_MAX;
        return validbst(root,mini,maxi);
    }
};