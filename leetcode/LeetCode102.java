import java.util.*;

public class LeetCode102 {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null)
            return result;

        List<List<TreeNode>> nodeLists = new ArrayList<>();
        nodeLists.add(Arrays.asList(new TreeNode[]{root}));
        result.add(Arrays.asList(new Integer[]{root.val}));

        for (int i = 0; i < nodeLists.size(); i++) {
            List<TreeNode> cnl = nodeLists.get(i);
            List<TreeNode> nnl = new ArrayList<>();
            List<Integer> nil = new ArrayList<>();

            for (TreeNode cn : cnl) {
                if (cn.left != null) {
                    nnl.add(cn.left);
                    nil.add(cn.left.val);
                }
                if (cn.right != null) {
                    nnl.add(cn.right);
                    nil.add(cn.right.val);
                }
            }
            if (nnl.size() != 0) {
                nodeLists.add(nnl);
                result.add(nil);
            }
        }
        return result;

    }
}
