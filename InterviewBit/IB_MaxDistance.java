import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class IB_MaxDistance {

    public static void main(String[] args) {
        System.out.println(new IB_MaxDistance().maximumGap(Arrays.asList(new Integer[]{1, 10}))); // 1
        System.out.println(new IB_MaxDistance().maximumGap(Arrays.asList(new Integer[]{3, 5, 4, 2}))); // 2
        System.out.println(new IB_MaxDistance().maximumGap(Arrays.asList(new Integer[]{3, 2, 1}))); // 0
    }
    public int maximumGap(final List<Integer> list) {

        List<Element> elements = new ArrayList<>(list.size());
        for (int i = 0; i < list.size(); i++) {
            elements.add(new Element(list.get(i), i));
        }
        // this is a stable sort
        Collections.sort(elements, (a, b) -> Integer.valueOf(a.ele).compareTo(Integer.valueOf(b.ele)));

        // calculating the maximum of suffix array
        int[] mi = new int[list.size()];
        int cm = -1;
        for (int i = list.size() - 1; i >= 0; i--) {
            mi[i] = cm;
            cm = Math.max(cm, elements.get(i).index);
        }
        int max = 0;
        for (int i = 0; i < list.size(); i++) {
            if (mi[i] >= 0 && mi[i] > elements.get(i).index && mi[i] - elements.get(i).index > max)
                max = mi[i] - elements.get(i).index;
        }
        return max;
    }

    private void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    private static class Element {
        int ele, index;

        public Element(int ele, int index) {
            this.ele = ele;
            this.index = index;
        }

        @Override
        public String toString() {
            return "[" + ele + "," + index + "]";
        }
    }

}
