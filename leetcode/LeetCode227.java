import java.util.*;

public class LeetCode227 {
    public static void main(String[] args) {
        System.out.println(new LeetCode227().calculate("3+9*4")); // 39
        System.out.println(new LeetCode227().calculate("3    +9")); // 12
        System.out.println(new LeetCode227().calculate(" 3    + 9 /2")); // 7
        System.out.println(new LeetCode227().calculate("    ")); // 0
        System.out.println(new LeetCode227().calculate(" 3  ")); // 3
        System.out.println(new LeetCode227().calculate(" 3/2 ")); // 1
        System.out.println(new LeetCode227().calculate("1+10/3*8-5")); // 20
        System.out.println(new LeetCode227().calculate("2*10/3*8-5+8")); // 51
        System.out.println(new LeetCode227().calculate("1*2-3/4+5*6-7*8+9/10")); // -24
    }

    public int calculate(String s) {
        s = s.trim();

        List<Integer> numbers = new ArrayList<>();
        List<Character> operators = new ArrayList<>();
        for (int i = 0; i < s.length(); ) {
            if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                int cn = 0;
                while (i < s.length() && s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                    cn = cn * 10 + s.charAt(i) - '0';
                    i++;
                }
                numbers.add(cn);
            } else if (s.charAt(i) == '+' || s.charAt(i) == '-' || s.charAt(i) == '*' || s.charAt(i) == '/') {
                operators.add(s.charAt(i));
                i++;
            } else i++;
        }
//        System.out.println(numbers + " \n" + operators);
        return find(numbers, operators);
    }

    private int find(List<Integer> numbers, List<Character> operators) {
        if (numbers.size() == 0) return 0;
        if (numbers.size() == 1) return numbers.get(0);
        Map<Character, Integer> pre = getPrecedenceMap();
        Deque<Integer> ns = new LinkedList<>();
        Deque<Character> os = new LinkedList<>();
        ns.push(numbers.get(0));
        ns.push(numbers.get(1));
        os.push(operators.get(0));
        int nc = 2, oc = 1;
        while (os.size() != 0) {
            if (oc == operators.size()) {
                while (os.size() != 0) {
                    int a = ns.pop();
                    int b = ns.pop();
                    char c = os.pop();

                    ns.push(compute(b, a, c));
                }
                return ns.pop();
            }
            int a = numbers.get(nc++);
            char c = operators.get(oc++);
            char stackTop = os.peek();
            if (pre.get(stackTop) < pre.get(c)) {
                ns.push(a);
                os.push(c);
            } else {
                while (os.size() > 0 && pre.get(os.peek()) >= pre.get(c)) {
                    int x = ns.pop();
                    int y = ns.pop();
                    int res = compute(y, x, os.pop());
                    ns.push(res);
                }
                os.push(c);
                ns.push(a);
            }
        }
        // should never be the case
        return -1;
    }

    private Map<Character, Integer> getPrecedenceMap() {
        Map<Character, Integer> pre = new HashMap<>();
        pre.put('+', 0);
        pre.put('-', 0);
        pre.put('*', 1);
        pre.put('/', 1);
        return pre;
    }

    private int compute(int x, int y, char op) {
        if (op == '+') return x + y;
        if (op == '-') return x - y;
        if (op == '*') return x * y;
        if (op == '/') return x / y;
        // should never happen as the input is valid
        return -1;
    }

}
