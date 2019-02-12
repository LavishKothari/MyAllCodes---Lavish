// without changing the node structure
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
import java.util.HashMap;
import java.util.Map;

public class LeetCode662 {
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

        System.out.println(new LeetCode662().widthOfBinaryTree(root));
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

        System.out.println(new LeetCode662().widthOfBinaryTree(root));
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

        System.out.println(new LeetCode662().widthOfBinaryTree(root));
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

        System.out.println(new LeetCode662().widthOfBinaryTree(root));
    }


    // root
    public int widthOfBinaryTree(TreeNode root) {
        if (root == null)
            return 0;
        Deque<TreeNode> queue = new ArrayDeque<>();
        queue.offer(root);
        int minCL = Integer.MAX_VALUE; // min for the current level
        int maxCL = Integer.MIN_VALUE; // max for the next level
        int answer = 1;
        int ncl = 1; // nodes in the current level
        int nnl = 0; // nodes in the next level
        /*
             for keeping index, as treenode won't have hashCode() defined,
             so the hashCode is assumed to be distince for different nodes
             depending on Object.hashCode() -> this can be particularly bad
             this solution will go wrong if already the hashCode is overriden
             in TreeNode and multiple TreeNodes can have same hash.
        */
        Map<TreeNode, Integer> indexMap = new HashMap<>();
        indexMap.put(root, 0);
        while (queue.size() != 0) {
            TreeNode cn = queue.poll(); // current node
            ncl--;

            if (cn.left != null) {
                queue.offer(cn.left);
                minCL = Math.min(minCL, indexMap.get(cn) * 2 + 1);
                maxCL = Math.max(maxCL, indexMap.get(cn) * 2 + 1);
                indexMap.put(cn.left, indexMap.get(cn) * 2 + 1);
                nnl++;
            }
            if (cn.right != null) {
                queue.offer(cn.right);
                minCL = Math.min(minCL, indexMap.get(cn) * 2 + 2);
                maxCL = Math.max(maxCL, indexMap.get(cn) * 2 + 2);
                indexMap.put(cn.right, indexMap.get(cn) * 2 + 2);
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

        public TreeNode(int val) {
            this.val = val;
        }
    }
}