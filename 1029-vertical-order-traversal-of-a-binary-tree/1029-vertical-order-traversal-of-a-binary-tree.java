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
    public List<List<Integer>> verticalTraversal(TreeNode root) {
          Map<Integer,TreeMap<Integer,PriorityQueue<Integer>>> nodes = new TreeMap<>();
          Queue<Pair<TreeNode,Pair<Integer,Integer>>> todo = new LinkedList<>();

          todo.offer(new Pair<>(root,new Pair<>(0,0)));

          while(!todo.isEmpty())
          {
            Pair<TreeNode,Pair<Integer,Integer>> p = todo.poll();
            TreeNode temp = p.getKey();
            int x= p.getValue().getKey();
            int y= p.getValue().getValue();

            nodes.computeIfAbsent(x, k-> new TreeMap<>())
                 .computeIfAbsent(y,k-> new PriorityQueue<>())
                 .offer(temp.val);
            
            if(temp.left!=null){
                todo.add(new Pair<>(temp.left,new Pair<>(x-1,y+1)));
            }
            if(temp.right!=null){
                todo.add(new Pair<>(temp.right,new Pair<>(x+1,y+1)));
            }
          }
          List<List<Integer>>ans = new ArrayList<>();
          for(TreeMap<Integer, PriorityQueue<Integer>> ys : nodes.values()){
            List<Integer> col = new ArrayList<>();
            for(PriorityQueue<Integer> pq : ys.values()){
                while(!pq.isEmpty())
                {
                    col.add(pq.poll());
                }
            }
            ans.add(col);
          }
          return ans;
    }
}