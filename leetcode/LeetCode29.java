
public class LeetCode29 {
    public static void main(String[] args) {
        System.out.println(new LeetCode29().divide(0, 1));
    }

    public int divide(int dividend, int divisor) {
        if (dividend == 0)
            return 0;
        int sign = Integer.signum(dividend) * Integer.signum(divisor);
        dividend = dividend < 0 ? -dividend : dividend;
        divisor = divisor < 0 ? -divisor : divisor;
        int low = 1, high = dividend;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (mid * divisor < dividend) {
                if ((long) mid * divisor + divisor > dividend) {
                    if ((long) mid * divisor + divisor > Integer.MAX_VALUE)
                        return Integer.MAX_VALUE;
                    return sign * mid;
                }
                low = mid;
            } else if (mid * divisor == dividend) {
                return sign * mid;
            } else {
                if ((long) mid * divisor - divisor < dividend) {
                    if ((long) mid * divisor - divisor < Integer.MIN_VALUE) {
                        return Integer.MAX_VALUE;
                    }
                    return sign * mid;
                }
                high = mid;
            }
        }
        return Integer.MAX_VALUE;
    }

}
