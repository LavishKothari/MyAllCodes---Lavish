public class LeetCode101 {
    public boolean isSymmetric(TreeNode root) {
        if (root == null)
            return true;
        return isSymmetric(root.left, root.right);
    }

    private boolean isSymmetric(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null) // both roots are null
            return true;
        if (root1 == null || root2 == null) // exactly one root is null
            return false;
        return root1.val == root2.val &&
                isSymmetric(root1.left, root2.right) &&
                isSymmetric(root1.right, root2.left);
    }
}
