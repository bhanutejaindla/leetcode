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
    TreeNode* lca(TreeNode* root,int p,int q)
    {
        if(root==nullptr) return root;
        TreeNode* leftside=lca(root->left,p,q);
        TreeNode* rightside=lca(root->right,p,q);
        if((leftside && rightside) || (root->val==p)|| (root->val==q))
        return root;
        return (leftside==nullptr)?rightside:leftside;
    }
    string lcaToStart,lcaToEnd;
    void dfs(TreeNode* root,string &pathString,int p,int q)
    {
        if(root==nullptr) return ;
        if(root->val==p) lcaToStart=pathString;
        if(root->val==q) lcaToEnd=pathString;
        pathString.push_back('L');
        dfs(root->left,pathString,p,q);
        pathString.pop_back();
        pathString.push_back('R');
        dfs(root->right,pathString,p,q);
        pathString.pop_back();
        return;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
          TreeNode* lcanode=lca(root,startValue,destValue);
          string pathString="";
          dfs(lcanode,pathString,startValue,destValue);
          for(auto &ch:lcaToStart)
          {
            ch='U';
          }
          cout<<lcaToStart<<endl;
          return lcaToStart+lcaToEnd;

    }
};