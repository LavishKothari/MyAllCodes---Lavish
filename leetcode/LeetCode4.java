import java.util.Objects;

public class LeetCode4 {
    public static void main(String[] args) {
        System.out.println(new LeetCode4().findMedianSortedArrays(
                new int[]{1, 2, 3, 4},
                new int[]{6, 7, 7, 8, 9, 12})); // 6.5

        System.out.println(new LeetCode4().findMedianSortedArrays(
                new int[]{1, 3},
                new int[]{2})); // 2.0

        System.out.println(new LeetCode4().findMedianSortedArrays(
                new int[]{},
                new int[]{1, 2, 10, 20})); // 6.0

        System.out.println(new LeetCode4().findMedianSortedArrays(
                new int[]{1, 2},
                new int[]{3, 4})); // 2.5
    }

    public double findMedianSortedArrays(final int[] a, final int[] b) {
        // can any list be null?
        Objects.requireNonNull(a);
        Objects.requireNonNull(b);

        int m = a.length, n = b.length;
        // can both the lists be empty (with no elements)?

        if (m > n) return findMedianSortedArrays(b, a);

        int start = 0, end = m;
        while (start <= end) {
            int mid = (start + end) / 2;

            // indices
            int l1 = mid;                   // these many elements of A on left side
            int r1 = m - l1;                // these many elements of A on right side
            int l2 = (r1 + n - mid) / 2;    // these many elements of B on left side
            int r2 = n - l2;                // these many elements of B on right side

            // values
            int aLeftMax = (l1 == 0 ? Integer.MIN_VALUE : a[l1 - 1]);
            int aRightMin = l1 == m ? Integer.MAX_VALUE : a[l1];
            int bLeftMax = (l2 == 0 ? Integer.MIN_VALUE : b[l2 - 1]);
            int bRightMin = l2 == n ? Integer.MAX_VALUE : b[l2];

            if (aLeftMax <= bRightMin && bLeftMax <= aRightMin) {
                // proper partition found
                if (isEven(m + n)) {
                    return avg(Math.max(aLeftMax, bLeftMax), Math.min(aRightMin, bRightMin));
                } else {
                    if (l1 + l2 > r1 + r2)
                        return Math.max(aLeftMax, bLeftMax);
                    else return Math.min(aRightMin, bRightMin);
                }
            } else if (aLeftMax > bRightMin) {
                end = mid - 1;
            } else if (bLeftMax > aRightMin) {
                start = mid + 1;
            } else {
                // both of the conditions can never be false together
                throw new IllegalArgumentException("It looks like the input lists are not sorted");
            }
        }
        // should never be the case
        throw new RuntimeException("this should have never occurred");
    }

    private boolean isEven(int a) {
        return (a & 1) == 0;
    }

    private double avg(int a, int b) {
        return (a + b) / 2.0;
    }

}
