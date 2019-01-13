import java.util.Arrays;
import java.util.List;

public class PE112 {
    private static final List<String> numbers = Arrays.asList(new String[]{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"});

    public static void main(String[] args) {
        int counter = 0;
        for (int i = 1; ; i++) {
            if (isBouncy(i)) {
                counter++;
                if (Double.compare((double) counter / i * 100.0, 99.0) == 0) {
                    System.out.println("answer = " + i);
                    break;
                }
            }
        }
    }

    private static boolean isBouncy(long n) {
        String str = getReverseString(n);
        return !isSorted(str);
    }

    private static boolean isSorted(String s) {
        if (s.length() == 0 || s.length() == 1)
            return true;

        boolean increasing = true, decreasing = true;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i - 1) > s.charAt(i)) {
                increasing = false;
            }
            if (s.charAt(i - 1) < s.charAt(i)) {
                decreasing = false;
            }
            if (!increasing && !decreasing) {
                return false;
            }
        }
        return increasing || decreasing;
    }

    private static String getReverseString(long n) {
        StringBuffer sb = new StringBuffer();
        while (n != 0) {
            sb.append(numbers.get((int) (n % 10)));
            n /= 10;
        }
        return sb.toString();
    }
}
