public class LeetCode337 {
    public int rob(TreeNode root) {
        return Math.max(getSpecific(root, true), getSpecific(root, false));
    }

    private int getSpecific(TreeNode root, boolean takeRoot) {
        if (root == null)
            return 0;
        int leftYes = 0, rightYes = 0, leftNo = 0, rightNo = 0;
        if (root.left != null) {
            leftNo = getSpecific(root.left, false);
            if (!takeRoot) {
                leftYes = getSpecific(root.left, true);
            }
        }
        if (root.right != null) {
            rightNo = getSpecific(root.right, false);
            if (!takeRoot) {
                rightYes = getSpecific(root.right, true);
            }
        }
        if (takeRoot)
            return root.val + leftNo + rightNo;
        else {
            return max4(leftYes + rightYes, leftNo + rightYes, leftYes + rightNo, leftNo + rightNo);
        }
    }

    private int max4(int a, int b, int c, int d) {
        return Math.max(Math.max(Math.max(a, b), c), d);
    }

}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}