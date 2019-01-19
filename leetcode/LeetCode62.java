public class LeetCode62 {
    public static void main(String[] args) {
        System.out.println(new LeetCode62().uniquePaths(1, 100));
    }

    public int uniquePaths(int m, int n) {
        long answer = 1;
        int max = Math.max(m, n);
        int min = Math.min(m, n);
        for (int i = max; i <= m + n - 2; i++) {
            answer *= i;
        }
        long minFact = 1;
        for (int i = 2; i < min; i++)
            minFact *= i;
        return (int) (answer / minFact);
    }

}
