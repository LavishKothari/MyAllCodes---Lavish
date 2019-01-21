import java.util.*;

public class LeetCode166 {
    public static void main(String[] args) {
//        System.out.println(new LeetCode166().fractionToDecimal(2, 5));
//        System.out.println(new LeetCode166().fractionToDecimal(2, 3));
//        System.out.println(new LeetCode166().fractionToDecimal(3, 13));
//        System.out.println(new LeetCode166().fractionToDecimal(1, 6));
//        System.out.println(new LeetCode166().fractionToDecimal(399601, 99900));
        System.out.println(new LeetCode166().fractionToDecimal(-1, -2147483648));
        System.out.println(new LeetCode166().fractionToDecimal(-2147483648, 1));

//        System.out.println(new LeetCode166().fractionToDecimal(50, 8));

    }

    public String fractionToDecimal(int n, int d) {
        long cn = n < 0 ? (long) n * -1 : n;
        long cd = d < 0 ? (long) d * -1 : d;
        int sign = Integer.signum(n) * Integer.signum(d);
        if (cn % cd == 0)
            return (sign == -1 ? "-" : "") + (cn / cd);


        long rem = cn % cd;
        StringBuffer result = new StringBuffer();
        result.append("" + (cn / cd) + ".");
        String decimal = get(rem, cd);
        result.append(decimal);
        return (sign == -1 ? "-" : "") + result.toString();
    }

    private String get(long rem, long d) {
        Set<Long> set = new HashSet<>();
        set.add(rem);
        StringBuffer result = new StringBuffer();
        Map<Long, Integer> map = new HashMap<>();
        int counter = 0;
        while (true) {

            map.put(rem, counter++);
            if (rem == 0) {
                return result.toString();
            }
            rem = rem * 10;
            result.append("" + (rem / d));
            if (rem >= d) {
                rem = rem % d;
                if (map.containsKey(rem)) {
                    int index = map.get(rem);
                    StringBuffer newResult = new StringBuffer();
                    newResult.append(result.substring(0, index));
                    newResult.append("(");
                    newResult.append(result.substring(index));
                    newResult.append(")");
                    return newResult.toString();
                }
            }
            set.add(rem);
        }
// should never be the case
        //return result.toString();
    }


}
