public class LeetCode13 {
    public static void main(String[] args) {
        System.out.println(new LeetCode13().romanToInt("III"));
        System.out.println(new LeetCode13().romanToInt("IV"));
        System.out.println(new LeetCode13().romanToInt("IX"));
        System.out.println(new LeetCode13().romanToInt("LVIII"));
        System.out.println(new LeetCode13().romanToInt("MCMXCIV"));
    }

    public int romanToInt(String s) {
        if (s == null || s.length() == 0) return 0;
        int answer = 0;
        for (int i = 0; i < s.length(); i++) {
            char cc = s.charAt(i);
            if (i < s.length() - 1) {
                char nc = s.charAt(i + 1);
                if (negative(cc, nc)) {
                    i++;
                    answer += toInt(nc) - toInt(cc);
                    continue;
                } else {
                    answer += toInt(cc);
                }
            } else {
                answer += toInt(cc);
            }
        }
        return answer;
    }

    private boolean negative(char cc, char nc) {
        if (cc == 'I' && (nc == 'V' || nc == 'X'))
            return true;
        if (cc == 'X' && (nc == 'L' || nc == 'C'))
            return true;
        if (cc == 'C' && (nc == 'D' || nc == 'M'))
            return true;
        return false;
    }

    private int toInt(char c) {
        if (c == 'I') return 1;
        if (c == 'V') return 5;
        if (c == 'X') return 10;
        if (c == 'L') return 50;
        if (c == 'C') return 100;
        if (c == 'D') return 500;
        return 1000;

    }
}
