import java.util.BitSet;
import java.util.HashSet;
import java.util.Set;

public class LeetCode10 {
    public static void main(String[] args) {

//        System.out.println(new LeetCode10().isMatch("abc", ".*abc")); // true
//        System.out.println(new LeetCode10().isMatch("abc", ".*bc")); // true
//        System.out.println(new LeetCode10().isMatch("abc", ".*c")); // true
//        System.out.println(new LeetCode10().isMatch("abc", ".*")); // true
//        System.out.println(new LeetCode10().isMatch("abcc", ".*a*b*c*")); // true
//        System.out.println(new LeetCode10().isMatch("cc", "c*")); // true
//
//        System.out.println(new LeetCode10().isMatch("", "a*b*c*a*")); // true
//        System.out.println(new LeetCode10().isMatch("bc", "a*bc")); // true
//        System.out.println(new LeetCode10().isMatch("abc", "a*bc")); // true
//        System.out.println(new LeetCode10().isMatch("c", "a*b*c")); // true
//        System.out.println(new LeetCode10().isMatch("aaabbc", "a*b*c")); // true
//        System.out.println(new LeetCode10().isMatch("aaabbc", "a*aaab*c")); // true
//        System.out.println(new LeetCode10().isMatch("aaaabc", "a*bc")); // true
//        System.out.println(new LeetCode10().isMatch("abca", "a*bc")); // false
//        System.out.println(new LeetCode10().isMatch("bc", "a*bca")); // false
//        System.out.println(new LeetCode10().isMatch("bc", "a*bbc")); // false
//
//
//        System.out.println(new LeetCode10().isMatch("aa", "a")); // false
//        System.out.println(new LeetCode10().isMatch("aa", "a*")); // true
//        System.out.println(new LeetCode10().isMatch("ab", ".*")); // true
//        System.out.println(new LeetCode10().isMatch("aab", "c*a*b")); // true
//        System.out.println(new LeetCode10().isMatch("mississippi", "mis*is*p*.")); // false
//
//
//        System.out.println(new LeetCode10().isMatch("aaa", "ab*a*c*a")); // true
//        System.out.println(new LeetCode10().isMatch("abc", ".*.*"));
        System.out.println(new LeetCode10().isMatch("aaca", "ab*a*c*a"));


//        System.out.println(new LeetCode10().normalize("a*bca"));
//        System.out.println(new LeetCode10().normalize("a*aaab*c"));
//        System.out.println(new LeetCode10().normalize("ab*c*bc"));
//        System.out.println(new LeetCode10().normalize("ab*c*cab"));
//        System.out.println(new LeetCode10().normalize("ab*a*c*a"));


    }

    private String normalize(String p) {
        BitSet take = new BitSet(p.length()); // all bits are initially false
        take.flip(0, p.length());
        Set<Character> clearSet = new HashSet<>();
        for (int i = 0; i < p.length(); i++) {
            if (clearSet.contains(p.charAt(i))) {
                take.set(i, false);
                if (i + 1 < p.length() && p.charAt(i + 1) == '*')
                    take.set(i + 1, false);
                continue;
            }
            if (i + 1 < p.length() && p.charAt(i + 1) == '*') {
                clearSet.add(p.charAt(i));
                i++;
            } else clearSet.clear();
        }
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < take.size(); i++) {
            if (take.get(i)) {
                sb.append(p.charAt(i));
            }
        }
        return sb.toString();
    }

    private boolean isEquivalentToEmpty(String p) {
        if (p.length() == 1)
            return false;
        for (int i = 1; i < p.length(); i += 2) {
            if (p.charAt(i) != '*')
                return false;
        }
        return true;
    }

    public boolean isMatch(String s, String p) {
        if (s.length() == 0 && p.length() == 0)
            return true;
        if (s.length() == 0 && isEquivalentToEmpty(p))
            return true;
        p = normalize(p);
        System.out.println(p);
        int si = 0, pi = 0;
        while (true) {
            if (si >= s.length() || pi >= p.length())
                break;
            char sc = s.charAt(si);
            char pc = p.charAt(pi);
            if (sc == pc) {
                si++;
                pi++;
            } else {
                if (pc == '.') {
                    si++;
                    pi++;
                } else if (pc == '*') {
                    char prev = p.charAt(pi - 1);
                    if (prev == '.') { // all together a different case
                        si--;
                        pi++;
                        if (pi == p.length())
                            return true;
                        boolean answer = false;
                        for (int i = si; i < s.length() && !answer; i++) {
                            answer = (answer || isMatch(s.substring(i), p.substring(pi)));
                        }
                        return answer;
                    }
                    while (pi < p.length() && (p.charAt(pi) == '*' || p.charAt(pi) == prev))
                        pi++;
                    while (si < s.length() && s.charAt(si) == prev)
                        si++;
                } else if (pi + 1 < p.length() && p.charAt(pi + 1) == '*') {
                    pi += 2;
                } else return false;
            }
        }
        if (isEquivalentToEmpty(p.substring(pi)))
            pi = p.length();
        return si == s.length() && pi == p.length();
    }

}
