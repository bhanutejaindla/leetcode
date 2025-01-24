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
    void inorder(TreeNode* root,unordered_map<int,int>&mp,int k,bool &flag)
    {
         if(!root) return ;
         if(mp.find(k-root->val)!=mp.end())
         {
            flag=true;
            return ;
         }
         mp[root->val]++;
         inorder(root->left,mp,k,flag);
         inorder(root->right,mp,k,flag);
         return ;
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root) return true;
        unordered_map<int,int>mp;
        bool flag=false;
        inorder(root,mp,k,flag);
        return flag;

    }
};