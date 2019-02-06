import java.util.ArrayList;
import java.util.Arrays;

public class IB_AddOneToNumber {
    public static void main(String[] args) {
        System.out.println((new IB_AddOneToNumber().plusOne(new ArrayList<>(Arrays.asList(new Integer[]{1, 2, 3})))));
        System.out.println((new IB_AddOneToNumber().plusOne(new ArrayList<>(Arrays.asList(new Integer[]{0, 2, 3})))));
        System.out.println((new IB_AddOneToNumber().plusOne(new ArrayList<>(Arrays.asList(new Integer[]{1, 9, 9})))));
        System.out.println((new IB_AddOneToNumber().plusOne(new ArrayList<>(Arrays.asList(new Integer[]{9, 9, 9})))));
        System.out.println((new IB_AddOneToNumber().plusOne(new ArrayList<>(Arrays.asList(new Integer[]{9})))));
        System.out.println((new IB_AddOneToNumber().plusOne(new ArrayList<>(Arrays.asList(new Integer[]{0})))));

    }

    public ArrayList<Integer> plusOne(ArrayList<Integer> list) {
        if (list == null || list.size() == 0)
            return new ArrayList<>();
        int counter = 0;
        while (counter < list.size() && list.get(counter) == 0) {
            counter++;
        }
        ArrayList<Integer> otherlist = new ArrayList<>(list.subList(counter, list.size()));
        if (otherlist.size() == 0)
            otherlist.add(0);
        int carry = 1;
        for (int i = otherlist.size() - 1; i >= 0; i--) {
            int val = otherlist.get(i) + carry;
            carry = val / 10;
            otherlist.set(i, val % 10);
            if (carry == 0)
                break;
        }
        if (carry != 0) {
            otherlist.add(0, carry);
        }
        return otherlist;
    }

}
