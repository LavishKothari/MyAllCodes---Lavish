import java.util.ArrayDeque;
import java.util.Deque;

public class LeetCode20 {

    public static void main(String[] args) {
        System.out.println(new LeetCode20().isValid("[(])")); // false
        System.out.println(new LeetCode20().isValid("()")); // true
        System.out.println(new LeetCode20().isValid("()[]{}")); // true
        System.out.println(new LeetCode20().isValid("(]")); // false
        System.out.println(new LeetCode20().isValid("({})")); // true
        System.out.println(new LeetCode20().isValid("{({()(){}})}")); // true
    }

    /*
     * [(]) // should return false
     */
    public boolean isValid(String s) {
        int paren = 0, curly = 0, square = 0;

        Deque<Character> stack = new ArrayDeque<>();
        for (int i = 0; i < s.length(); i++) {
            char cc = s.charAt(i);
            if (stack.size() == 0) {
                if (isClosing(cc))
                    return false;
                stack.push(cc);
            } else {
                if (isClosing(cc)) {
                    if (match(stack.peek(), cc))
                        stack.pop();
                    else return false;
                } else stack.push(cc);
            }
        }
        return stack.size() == 0;
    }

    public boolean isOpening(char c) {
        return c == '(' || c == '[' || c == '{';
    }

    public boolean isClosing(char c) {
        return !isOpening(c);
    }

    public boolean match(char a, char b) {
        return (a == '{' && b == '}') ||
                (a == '[' && b == ']') ||
                (a == '(' && b == ')');
    }
}
