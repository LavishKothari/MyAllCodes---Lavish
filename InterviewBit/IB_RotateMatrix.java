import java.util.ArrayList;
import java.util.Arrays;

public class IB_RotateMatrix {
    public static void main(String[] args) {
        test1(); // for odd
        test2(); // for even
    }

    private static void test1() {
        ArrayList<ArrayList<Integer>> list = new ArrayList<>();

        list.add(new ArrayList<>(Arrays.asList(Integer.valueOf(1), Integer.valueOf(2), Integer.valueOf(3))));
        list.add(new ArrayList<>(Arrays.asList(Integer.valueOf(4), Integer.valueOf(5), Integer.valueOf(6))));
        list.add(new ArrayList<>(Arrays.asList(Integer.valueOf(7), Integer.valueOf(8), Integer.valueOf(9))));

        new IB_RotateMatrix().rotate(list);
        System.out.println(list);

    }

    private static void test2() {
        ArrayList<ArrayList<Integer>> list = new ArrayList<>();

        list.add(new ArrayList<>(Arrays.asList(Integer.valueOf(1), Integer.valueOf(2),
                Integer.valueOf(3), Integer.valueOf(4))));
        list.add(new ArrayList<>(Arrays.asList(Integer.valueOf(5), Integer.valueOf(6),
                Integer.valueOf(7), Integer.valueOf(8))));
        list.add(new ArrayList<>(Arrays.asList(Integer.valueOf(9), Integer.valueOf(10),
                Integer.valueOf(11), Integer.valueOf(12))));
        list.add(new ArrayList<>(Arrays.asList(Integer.valueOf(13), Integer.valueOf(14),
                Integer.valueOf(15), Integer.valueOf(16))));

        new IB_RotateMatrix().rotate(list);
        System.out.println(list);

    }

    public void rotate(ArrayList<ArrayList<Integer>> a) {
        int n = a.size();
        int x, y;
        // counter is the ring number, 0 being the outermost one
        for (int counter = 0; counter < n; counter++) {
            int x1 = counter, y1 = counter;
            int x2 = counter, y2 = n - 1 - counter;
            int x3 = n - 1 - counter, y3 = n - 1 - counter;
            int x4 = n - 1 - counter, y4 = counter;

            for (int i = 0; i < n - 2 * counter - 1; i++, y1++, x2++, y3--, x4--) {
                swap(a, x1, y1, x2, y2);
                swap(a, x1, y1, x3, y3);
                swap(a, x1, y1, x4, y4);
            }
        }
    }

    private void swap(ArrayList<ArrayList<Integer>> a, int x1, int y1, int x2, int y2) {
        int temp = a.get(x1).get(y1);
        a.get(x1).set(y1, a.get(x2).get(y2));
        a.get(x2).set(y2, temp);
    }

}
