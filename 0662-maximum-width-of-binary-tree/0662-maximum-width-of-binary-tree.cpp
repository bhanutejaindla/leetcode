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
    int widthOfBinaryTree(TreeNode* root) {
         if(!root) return 0;
         queue<pair<TreeNode*,long long >>q;
         q.push({root,0});
         int ans=0;
         while(!q.empty())
         {
            int size=q.size();
            int mini=INT_MAX;
            int maxi=INT_MIN;
            int ref=q.front().second;
            for(int i=0;i<size;i++)
            {
                TreeNode* a=q.front().first;
                int b=q.front().second-ref;
                cout<<b<<endl;
                mini=min(mini,b);
                maxi=max(maxi,b);
                q.pop();
                if(a->left)
                {
                    q.push({a->left,(long long)2*b+1});
                }
                if(a->right)
                {
                    q.push({a->right,(long long)2*b+2});
                }
            }
            ans=max(ans,maxi-mini+1);
         }
         return ans;
    }
};