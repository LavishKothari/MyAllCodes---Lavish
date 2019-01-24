import java.util.*;

public class LeetCode208 {
    public static void main(String[] args) {
        Trie trie = new Trie();

        trie.insert("apple");
        System.out.println(trie.search("apple"));   // returns true
        System.out.println(trie.search("app"));     // returns false
        System.out.println(trie.startsWith("app")); // returns true
        trie.insert("app");
        System.out.println(trie.search("app"));     // returns true
        System.out.println(trie.startsWith("apples"));
        System.out.println(trie.startsWith("x")); // false
        trie.insert("apples");
        System.out.println(trie.startsWith("apples")); // true
        System.out.println(trie.search("apples")); // true
        System.out.println(trie.search("apple")); // true


    }
}

class Trie {
    private static class Node {
        private boolean isFinished;
        private List<Node> children = new ArrayList<>(26);

        public Node(boolean isFinished) {
            this.isFinished = isFinished;
            for (int i = 0; i < 26; i++)
                children.add(null);
        }

        public void setIsFinished(boolean isFinished) {
            this.isFinished = isFinished;
        }
    }

    private Node head;

    /**
     * Initialize your data structure here.
     */
    public Trie() {
        head = new Node(false);
    }

    /**
     * Inserts a word into the trie.
     */
    public void insert(String word) {
        Node currentNode = head;
        for (int i = 0; i < word.length(); i++) {
            char currentChar = word.charAt(i);
            if (currentNode.children.get(currentChar - 'a') == null) {
                currentNode.children.set(currentChar - 'a', new Node(false));
            }
            currentNode = currentNode.children.get(currentChar - 'a');
        }
        currentNode.setIsFinished(true);
    }

    /**
     * Returns if the word is in the trie.
     */
    public boolean search(String word) {
        Node currentNode = head;
        for (int i = 0; i < word.length(); i++) {
            char currentChar = word.charAt(i);
            if (currentNode.children.get(currentChar - 'a') == null) {
                return false;
            }
            currentNode = currentNode.children.get(currentChar - 'a');
        }
        return currentNode.isFinished;
    }

    /**
     * Returns if there is any word in the trie that starts with the given prefix.
     */
    public boolean startsWith(String word) {
        Node currentNode = head;
        for (int i = 0; i < word.length(); i++) {
            char currentChar = word.charAt(i);
            if (currentNode.children.get(currentChar - 'a') == null) {
                return false;
            }
            currentNode = currentNode.children.get(currentChar - 'a');
        }
        return true;
    }

}
