public class LeetCode50 {
    public static void main(String[] args) {
        System.out.println(new LeetCode50().myPow(2.0, 10));
        System.out.println(new LeetCode50().myPow(2.1, 3));
        System.out.println(new LeetCode50().myPow(2.0, -2));
        System.out.println(new LeetCode50().myPow(2.0, 10));

    }

    public double myPow(double x, int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        double temp = myPow(x, n / 2);
        if ((n & 1) != 0 && n < 0)
            return temp * temp / x;
        else if ((n & 1) != 0 && n > 0)
            return temp * temp * x;
        return temp * temp;
    }

}
