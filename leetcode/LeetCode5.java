public class LeetCode5 {
    public static void main(String[] args) {
        System.out.println(new LeetCode5().longestPalindrome(""));
        System.out.println(new LeetCode5().longestPalindrome(null));
        System.out.println(new LeetCode5().longestPalindrome("babad"));
        System.out.println(new LeetCode5().longestPalindrome("cbbd"));
        System.out.println(new LeetCode5().longestPalindrome("bbbabbbcbbd"));
    }

    public String longestPalindrome(String s) {
        if (s == null || s.length() == 0) return "";
        int n = s.length();
        Pair max = new Pair(0, 0);
        for (int i = 0; i < n; i++) {
            Pair p1 = longest(s, i - 1, i + 1);
            Pair p2 = longest(s, i, i + 1);
            max = p1 != null && max.compareTo(p1) < 0 ? p1 : max;
            max = p2 != null && max.compareTo(p2) < 0 ? p2 : max;
        }
        return s.substring(max.x, max.y + 1);
    }

    private Pair longest(String s, int a, int b) {
        int n = s.length();
        if (a < 0 || b >= n) return null;
        while (a >= 0 && b < n && s.charAt(a) == s.charAt(b)) {
            a--;
            b++;
        }
        if (a + 1 > b - 1) return null;
        return new Pair(a + 1, b - 1);
    }

    private static class Pair implements Comparable<Pair> {
        int x, y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Pair p) {
            return Integer.compare(this.y - this.x + 1, p.y - p.x + 1);
        }
    }


}
