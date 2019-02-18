public class LeetCode7 {
    public static void main(String[] args) {
        System.out.println(new LeetCode7().reverse(-5)); // -5
        System.out.println(new LeetCode7().reverse(123)); // 321
        System.out.println(new LeetCode7().reverse(-123)); // -321
        System.out.println(new LeetCode7().reverse(1534236469)); // 0
        System.out.println(new LeetCode7().reverse(-2147483648)); // 0
    }

    /**
     * @param x
     * @return reverse of the number, 0 if there is an integer overflow
     */
    public int reverse(int x) {
        long result = 0;
        while (x != 0) {
            result = result * 10 + x % 10;
            x /= 10;
        }
        return result > Integer.MAX_VALUE || result < Integer.MIN_VALUE ? 0 : (int) result;
    }
}
