import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class SubArray {
    int start, end, startEle;
    long sum;

    public SubArray(int start, int end, long sum, int startEle) {
        this.start = start;
        this.end = end;
        this.sum = sum;
        this.startEle = startEle;
    }

    public int getLength() {
        return end - start + 1;
    }
}

public class IB_MaxNonNegativeSubarray {
    public static void main(String[] args) {
        System.out.println(new IB_MaxNonNegativeSubarray().maxset(new ArrayList<>(
                Arrays.asList(new Integer[]{1, 2, 5, -7, 2, 3}))));
        System.out.println(new IB_MaxNonNegativeSubarray().maxset(new ArrayList<>(
                Arrays.asList(new Integer[]{1, 2, -5, -7, 1, 1, 1}))));
        System.out.println(new IB_MaxNonNegativeSubarray().maxset(new ArrayList<>(
                Arrays.asList(new Integer[]{10, 20, -5, -7, 10, 10, 10, -9, 5, 15, 5, 5}))));
        System.out.println(new IB_MaxNonNegativeSubarray().maxset(new ArrayList<>(
                Arrays.asList(new Integer[]{10, 20, -5, -7, 10, 10, 10, -9, 5, 15, 10}))));
        System.out.println(new IB_MaxNonNegativeSubarray().maxset(new ArrayList<>(
                Arrays.asList(new Integer[]{336465782, -278722862, -2145174067, 1101513929,
                        1315634022, -1369133069, 1059961393, 628175011, -1131176229, -859484421}))));


    }

    public ArrayList<Integer> maxset(ArrayList<Integer> list) {
        List<SubArray> subList = new ArrayList();
        SubArray current = new SubArray(-1, -1, -1, -1);
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i) < 0) {
                if (current.start != -1) {
                    subList.add(current);
                    current = new SubArray(-1, -1, -1, -1);
                }
            } else {
                if (current.start == -1) {
                    current.start = current.end = i;
                    current.sum = current.startEle = list.get(i);
                } else {
                    current.end = i;
                    current.sum += list.get(i);
                }
            }
        }
        if (current.start != -1) {
            subList.add(current);
        }

        if (subList.size() == 0)
            return new ArrayList<>();
        SubArray maxSubArray = subList.get(0);
        for (int i = 1; i < subList.size(); i++) {
            if (maxSubArray.sum < subList.get(i).sum) {
                maxSubArray = subList.get(i);
            } else if (maxSubArray.sum == subList.get(i).sum) {
                if (maxSubArray.getLength() < subList.get(i).getLength()) {
                    maxSubArray = subList.get(i);
                } else if (maxSubArray.getLength() == subList.get(i).getLength()) {
                    if (maxSubArray.startEle > subList.get(i).startEle)
                        maxSubArray = subList.get(i);
                }
            }
        }
        return new ArrayList<>(list.subList(maxSubArray.start, maxSubArray.end + 1));
    }

}
