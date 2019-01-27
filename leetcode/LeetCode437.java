public class LeetCode437 {
    public int pathSum(TreeNode root, int sum) {
        if (root == null)
            return 0;
        return pathSum(root.left, sum) +
                pathSum(root.right, sum) +
                pathSumHelper(root, sum);
    }

    public int pathSumHelper(TreeNode root, int sum) {
        if (root == null) {
            return 0;
        }
        int c = pathSumHelper(root.left, sum - root.val);
        int d = pathSumHelper(root.right, sum - root.val);
        int answer = (root.val == sum ? 1 : 0);
        return c + d + answer;
    }
}
