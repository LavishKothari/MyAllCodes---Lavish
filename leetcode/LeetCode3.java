import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class LeetCode3 {
    public static void main(String[] args) {
        System.out.println(new LeetCode3().lengthOfLongestSubstring("")); // 0
        System.out.println(new LeetCode3().lengthOfLongestSubstring("abcabcbb")); // 3
        System.out.println(new LeetCode3().lengthOfLongestSubstring("bbbbb")); // 1
        System.out.println(new LeetCode3().lengthOfLongestSubstring("pwwkew")); // 3
        System.out.println(new LeetCode3().lengthOfLongestSubstring("aaabbbccc")); // 2
    }

    // O(n^2) solution
    public int lengthOfLongestSubstring1(String s) {
        if (s == null || s.length() == 0) return 0;
        int n = s.length();
        int answer = 1;
        for (int i = 0; i < n; i++) {
            Set<Character> set = new HashSet<>();
            for (int j = i; j < n; j++) {
                if (!set.contains(s.charAt(j))) {
                    set.add(s.charAt(j));
                    answer = Math.max(answer, set.size());
                } else {
                    break;
                }
            }
        }
        return answer;
    }

    // O(n) solution - time complexity

    /**
     * The main idea here is to keep track of the last index
     * where each character was seen while traversing the string
     * from left to right.
     *
     */
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() == 0) return 0;
        Map<Character, Integer> map = new HashMap<>();
        int answer = 1;
        int lastIndex = -1;
        for (int i = 0; i < s.length(); i++) {
            lastIndex = Math.max(lastIndex, map.containsKey(s.charAt(i)) ? map.get(s.charAt(i)) : -1);
            map.put(s.charAt(i), i);
            answer = Math.max(answer, i - lastIndex);
        }
        return answer;
    }

}
