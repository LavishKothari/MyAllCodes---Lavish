import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

public class LeetCode94 {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.right = new TreeNode(2);
        root.right.left = new TreeNode(3);
        System.out.println(new LeetCode94().inorderTraversal(root));

    }

    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        iterative(root, list);
        return list;
    }

    private void iterative(TreeNode root, List<Integer> list) {
        Deque<TreeNode> stack = new LinkedList<>();
        while (root != null) {
            stack.push(root);
            root = root.left;
        }
        while (stack.size() != 0) {
            TreeNode currentRoot = stack.pop();
            list.add(currentRoot.val);
            currentRoot = currentRoot.right;
            while (currentRoot != null) {
                stack.push(currentRoot);
                currentRoot = currentRoot.left;
            }
        }
    }

    private void recursive(TreeNode root, List<Integer> list) {
        if (root == null)
            return;
        recursive(root.left, list);
        list.add(root.val);
        recursive(root.right, list);
    }

    private static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

}
