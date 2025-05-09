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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        st1.push(root);
        vector<int>v;
        while(!st1.empty())
        {
            root=st1.top();
            st1.pop();
            st2.push(root);
            if(root->left)
            {
                st1.push(root->left);
            }
            if(root->right)
            {
                st1.push(root->right);
            }
        }
        while(!st2.empty())
        {
            v.push_back(st2.top()->val);
            st2.pop();
        }
        return v;

    }
};