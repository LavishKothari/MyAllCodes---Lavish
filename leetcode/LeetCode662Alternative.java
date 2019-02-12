/*
        Question :
        Given a binary tree, write a function to get the row with maximum width in the tree.
        The width of one row is defined as the length between the end-nodes
        (the leftmost and right most non-null nodes in the level,
        where the null nodes between the end-nodes are also counted into the length calculation.)
               1	    		   0
           2      3	           1		2
        4   .  6   	.        3	 .    5	  .

        5-3+1 = 3
*/

import java.util.ArrayDeque;
import java.util.Deque;

public class LeetCode662Alternative {
    public static void main(String[] args) {
        test1(); // 2
        test2(); // 4
        test3(); // 3
        test4(); // 1
    }

    private static void test1() {
        /*
                1
              2   3
              answer should be 2
         */
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);

        System.out.println(new LeetCode662Alternative().getMaxWidth(root));
    }

    private static void test2() {
        /*
                    1
                 2       3
             4     .  .      5
             answer should be 4
         */
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.right.right = new TreeNode(5);

        System.out.println(new LeetCode662Alternative().getMaxWidth(root));
    }

    private static void test3() {
        /*
                     1
                2         3
             .     4    .    5
             answer should be 3
         */
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.right = new TreeNode(4);
        root.right.right = new TreeNode(5);

        System.out.println(new LeetCode662Alternative().getMaxWidth(root));
    }

    private static void test4() {
        /*
                           1
                     .            2
                 .      .     .       3
                . .    . .   . .     .  4
             answer should be 1
         */
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.left.left = new TreeNode(3);
        root.left.left.left = new TreeNode(4);

        System.out.println(new LeetCode662Alternative().getMaxWidth(root));
    }


    // root
    public int getMaxWidth(TreeNode root) {
        if (root == null)
            return 0;
        Deque<TreeNode> queue = new ArrayDeque<>();
        // root.index = 0; // is already 0, you don't need to explicitly do this
        queue.offer(root);
        int minCL = Integer.MAX_VALUE; // min of current level
        int maxCL = Integer.MIN_VALUE; // max of current level
        int answer = 1;
        int ncl = 1; // nodes in current level
        int nnl = 0; // nodes in next level
        while (queue.size() != 0) {
            TreeNode cn = queue.poll(); // current node
            ncl--;

            if (cn.left != null) {
                queue.offer(cn.left);
                minCL = Math.min(minCL, cn.index * 2 + 1);
                maxCL = Math.max(maxCL, cn.index * 2 + 1);
                cn.left.index = cn.index * 2 + 1;
                nnl++;
            }
            if (cn.right != null) {
                queue.offer(cn.right);
                minCL = Math.min(minCL, cn.index * 2 + 2);
                maxCL = Math.max(maxCL, cn.index * 2 + 2);
                cn.right.index = cn.index * 2 + 2;
                nnl++;
            }
            if (ncl == 0) {
                ncl = nnl;
                nnl = 0;
                if (minCL != Integer.MAX_VALUE && maxCL != Integer.MIN_VALUE) {
                    if (maxCL - minCL + 1 > answer)
                        answer = maxCL - minCL + 1;
                    minCL = Integer.MAX_VALUE;
                    maxCL = Integer.MIN_VALUE;
                }
            }
        }
        return answer;
    }

    static class TreeNode {
        int val;
        TreeNode left, right;
        int index;

        public TreeNode(int val) {
            this.val = val;
        }
    }
}