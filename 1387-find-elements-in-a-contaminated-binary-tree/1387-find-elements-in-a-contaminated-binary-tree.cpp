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
class FindElements {
public:
   unordered_set<int>s;
    FindElements(TreeNode* root) {
        if(!root) return ;
        root->val=0;
        s.insert(root->val);
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
           int size=q.size();
           for(int i=0;i<size;i++)
           {
             TreeNode* a=q.front();
             q.pop();
             if(a->left)
             {
                a->left->val=(2*(a->val))+1;
                s.insert(a->left->val);
                q.push(a->left);
             }
             if(a->right)
             {
                a->right->val=(2*(a->val))+2;
                s.insert(a->right->val);
                q.push(a->right);
             }
           }
        }
    }
    
    bool find(int target) {
        if(s.find(target)!=s.end()) return true;
        else return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */