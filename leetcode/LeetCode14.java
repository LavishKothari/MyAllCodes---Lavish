public class LeetCode14 {
    public static void main(String[] args) {
        System.out.println(new LeetCode14().longestCommonPrefix(new String[]{"", "ac"}));
        System.out.println(new LeetCode14().longestCommonPrefix(new String[]{"flower", "flow", "flight"}));
        System.out.println(new LeetCode14().longestCommonPrefix(new String[]{"dog", "racecar", "car"}));
    }
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) return "";
        StringBuilder sb = new StringBuilder();
        char cc;
        for (int x = 0; ; x++) { // for characters
            if (x < strs[0].length())
                cc = strs[0].charAt(x);
            else return strs[0].substring(0, x);
            for (int i = 0; i < strs.length; i++) { // for each string
                if (x >= strs[i].length() || strs[i].charAt(x) != cc)
                    return strs[i].substring(0, x);
            }
        }
    }
}
