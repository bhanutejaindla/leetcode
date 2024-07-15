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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>nodes;
        int n=descriptions.size();
        unordered_map<int,bool>ischild;
        for(int i=0;i<n;i++)
        {
            int parent=descriptions[i][0];
            int child=descriptions[i][1];
            int isleft=descriptions[i][2];
            if(nodes.find(parent)==nodes.end())
            {
                nodes[parent]=new TreeNode(parent);
            }
            if(nodes.find(child)==nodes.end())
            {
                nodes[child]=new TreeNode(child);
            }
            if(isleft)
            {
                nodes[parent]->left=nodes[child];
            }
            else
            {
                nodes[parent]->right=nodes[child];
            }
            ischild[child]=true;
        }
        TreeNode* root=nullptr;
        for(const auto &v:nodes)
        {
            if(ischild.find(v.first)==ischild.end())
            {
                root=v.second;
                break;
            }
        }
        return root;
    }
};