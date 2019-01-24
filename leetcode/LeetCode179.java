import java.util.*;

public class LeetCode179 {
    public static void main(String[] args) {
        System.out.println(new LeetCode179().largestNumber(new int[]{0,0, 1}));
    }

    public String largestNumber(int[] nums) {
        List<Integer> list = new ArrayList<>(nums.length);
        for (int i : nums) {
            list.add(i);
        }
        Collections.sort(list, new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                String afirst = a.toString() + b.toString();
                String bfirst = b.toString() + a.toString();
                Long af = Long.parseLong(afirst); // this should be long
                Long bf = Long.parseLong(bfirst); // this should be long
                return -1 * af.compareTo(bf);
            }
        });
        StringBuffer result = new StringBuffer();
        for (int i = 0; i < nums.length; i++) {
            result.append(list.get(i));
        }
        int firstNonZero = 0;
        while(firstNonZero< result.length() && result.charAt(firstNonZero) == '0') {
            firstNonZero++;
        }
        if(firstNonZero == result.length()) {
            result = new StringBuffer("0");
        } else {
            result = new StringBuffer(result.substring(firstNonZero));
        }
        return result.toString();
    }

}
