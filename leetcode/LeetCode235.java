public class LeetCode235 {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        TreeNode cn = root;
        while (cn != null) {
            if (cn.val > p.val && cn.val > q.val)
                cn = cn.left;
            else if (cn.val < p.val && cn.val < q.val)
                cn = cn.right;
            else if (cn.val == p.val)
                return cn;
            else if (cn.val == q.val)
                return cn;
            else return cn;
        }
        // should never be the case
        return null;
    }
}
