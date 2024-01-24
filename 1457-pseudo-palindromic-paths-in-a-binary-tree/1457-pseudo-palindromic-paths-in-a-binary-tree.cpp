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
    bool check(unordered_map<int,int>&mp)
    {
        int v=0;
        for(auto x:mp)
        {
            if(x.second%2==1) v++;
        }
        return v<=1;
    }
    void helper(TreeNode* root,unordered_map<int,int>&mp,int &cnt)
    {

        if(root==NULL)
        {
            return ;
        }
        mp[root->val]++;
        if(!root->left && !root->right)
        {
             if(check(mp))  cnt++;
        }
        helper(root->left,mp,cnt);
        helper(root->right,mp,cnt);
        mp[root->val]--;
        return ;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt=0;
        unordered_map<int,int>mp;
        helper(root,mp,cnt);
        return cnt;
    }
};