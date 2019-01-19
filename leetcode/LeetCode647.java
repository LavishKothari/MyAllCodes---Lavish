public class LeetCode647 {
    public static void main(String[] args) {
        System.out.println("answer = " + new LeetCode647().countSubstrings("abc"));
        System.out.println("answer = " + new LeetCode647().countSubstrings("aaa"));

    }

    public int countSubstrings(String s) {
        int[][] cache = new int[s.length()][s.length()];
        // make all the elements of cache -1
        for (int i = 0; i < cache.length; i++) {
            for (int j = 0; j < cache[i].length; j++) {
                cache[i][j] = -1;
            }
        }
        int answer = 0;
        for (int i = 0; i < cache.length; i++) {
            for (int j = i; j < cache[i].length; j++) {
                cache[i][j] = isPal(s, i, j, cache);
                if (cache[i][j] == 1) {
                    answer++;
                }
            }
        }

        return answer;
    }

    private int isPal(String s, int i, int j, int[][] cache) {
        if (i == j || j - i == 1)
            return s.charAt(i) == s.charAt(j) ? 1 : 0;
        if (cache[i][j] != -1)
            return cache[i][j];
        if (isPal(s, i + 1, j - 1, cache) == 1 && s.charAt(i) == s.charAt(j))
            cache[i][j] = 1;
        else
            cache[i][j] = 0;
        return cache[i][j];

    }
}
