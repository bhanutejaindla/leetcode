/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public static void helper(TreeNode root,Map<Integer,Integer>mp,int level)
    {
         if(root==null) return ;
         if(!mp.containsKey(level))
         {
            mp.put(level,root.val);
         }
         helper(root.right,mp,level+1);
         helper(root.left,mp,level+1);
         return ;
    }
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        if(root==null) return ans;
        Map<Integer,Integer>mp=new TreeMap<>();
        helper(root,mp,0);
        for(Integer p : mp.values())
        {
            ans.add(p);
        }
        return ans;
    }
}