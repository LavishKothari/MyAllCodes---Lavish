class Solution394 {
    public static void main(String[] args) {
        System.out.println(new Solution394().decodeString("3[a]2[bc]"));
        System.out.println(new Solution394().decodeString("3[a2[c]]"));
        System.out.println(new Solution394().decodeString("3[a]2[b4[F]c]"));

    }

    public String decodeString(String s) {
        StringBuffer result = new StringBuffer();
        for (int i = 0; i < s.length(); i++) {
            char cc = s.charAt(i);
            if ((cc >= 'a' && cc <= 'z') || (cc >= 'A' && cc <= 'Z')) {
                result.append("" + cc);
            } else if (cc >= '0' && cc <= '9') {
                int repetition = getInt(s, i);
                while (s.charAt(i) != '[')
                    i++;
                String withinBracket = getWithinBracket(s, i + 1);
                String resultOfWithin = decodeString(withinBracket);
                for (int j = 0; j < repetition; j++) {
                    result.append(resultOfWithin);
                }
                i += withinBracket.length() + 1;
            }
        }
        return result.toString();
    }

    private int getInt(String s, int index) {
        int result = 0;
        for (int i = index; i < s.length(); i++) {
            char cc = s.charAt(i);
            if (cc == '[') {
                assert result != 0;
                return result;
            }
            assert cc >= '0' && cc <= '9';
            result = result * 10 + (cc - '0');
        }
        return result;
    }

    private String getWithinBracket(String s, int index) {
        int open = 0;
        for (int i = index; i < s.length(); i++) {
            char cc = s.charAt(i);
            if (cc == '[')
                open++;
            else if (cc == ']')
                open--;
            if (open < 0)
                return s.substring(index, i);
        }
        // this should never happen
        return "";
    }

}
