/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool path(TreeNode* root,TreeNode* q,vector<int>&v)
    {
        if(!root)  return false;
         v.push_back(root->val);
        if(root==q) 
        {
            return true;
        }
       
        if(path(root->left,q,v) || path(root->right,q,v)) return true;
        v.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int>v,v1;
        path(root,p,v);
        path(root,q,v1);
        int a=0;
        for(int i=0;i<min(v.size(),v1.size());i++)
        {
           if(v[i]==v1[i])
           {
                a=v[i];
           }
           else break;
        }
        return new TreeNode(a);
    }
};