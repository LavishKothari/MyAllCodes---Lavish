import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class LeetCode22 {
    public static void main(String[] args) {
        System.out.println(new LeetCode22().generateParenthesis(1));
        System.out.println(new LeetCode22().generateParenthesis(2));
        System.out.println(new LeetCode22().generateParenthesis(3));
        System.out.println(new LeetCode22().generateParenthesis(4));


    }

    public List<String> generateParenthesis(int n) {
        if (n == 0)
            return new ArrayList<>();
        if (n == 1) {
            List<String> list = new ArrayList<>(1);
            list.add("()");
            return list;
        }
        List<String> list = generateParenthesis(n - 1);
        Set<String> result = new HashSet<>();
        for (String current : list) {
            for (int i = 1; i <= current.length(); i++) {
                for (int j = i; j < current.length(); j++) {
                    StringBuffer sb = new StringBuffer();
                    sb.append(current.substring(0, i));
                    sb.append("(");
                    sb.append(current.substring(i, j));
                    sb.append(")");
                    sb.append(current.substring(j));
                    result.add(sb.toString());
                }
            }
            result.add(current + "()");
            result.add("()" + current);
        }
        return new ArrayList<>(result);
    }

}
