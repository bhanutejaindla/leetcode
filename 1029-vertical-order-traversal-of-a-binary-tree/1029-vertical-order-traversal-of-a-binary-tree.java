class Solution {
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        TreeMap<Integer, TreeMap<Integer, PriorityQueue<Integer>>> map = new TreeMap<>();
        Queue<Pair<TreeNode, Pair<Integer, Integer>>> q = new LinkedList<>();
        q.offer(new Pair<>(root, new Pair<>(0, 0))); // Pair<TreeNode, (x, y)>

        while (!q.isEmpty()) {
            Pair<TreeNode, Pair<Integer, Integer>> p = q.poll();
            TreeNode node = p.getKey();
            int x = p.getValue().getKey();
            int y = p.getValue().getValue();

            map
                .computeIfAbsent(x, k -> new TreeMap<>())
                .computeIfAbsent(y, k -> new PriorityQueue<>())
                .offer(node.val);

            if (node.left != null)
                q.offer(new Pair<>(node.left, new Pair<>(x - 1, y + 1)));
            if (node.right != null)
                q.offer(new Pair<>(node.right, new Pair<>(x + 1, y + 1)));
        }

        List<List<Integer>> result = new ArrayList<>();
        for (TreeMap<Integer, PriorityQueue<Integer>> ys : map.values()) {
            List<Integer> col = new ArrayList<>();
            for (PriorityQueue<Integer> pq : ys.values()) {
                while (!pq.isEmpty()) {
                    col.add(pq.poll());
                }
            }
            result.add(col);
        }

        return result;
    }
}
