import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

public class IB_MergeIntervals {
    public static void main(String[] args) {
        {
            ArrayList<Interval> intervals = new ArrayList<>(Arrays.asList(
                    new Interval(1, 3), new Interval(6, 9)));
            System.out.println(new IB_MergeIntervals().insert(intervals, new Interval(2, 5)));
        }
        {
            ArrayList<Interval> intervals = new ArrayList<>(Arrays.asList(
                    new Interval(1, 2), new Interval(3, 5), new Interval(6, 7),
                    new Interval(8, 10), new Interval(12, 16)));
            System.out.println(new IB_MergeIntervals().insert(intervals, new Interval(4, 9)));
        }

    }

    public ArrayList<Interval> insert(ArrayList<Interval> intervals, Interval newInterval) {
        Comparator<Interval> cmp = (int1, int2) -> {
            if (int1.start < int2.start) return -1;
            else if (int1.start > int2.start) return 1;
            else if (int1.end < int2.end) return -1;
            else if (int1.end > int2.end) return 1;
            else return 0;
        };
        ArrayList<Interval> result = new ArrayList<>(intervals);
        result.add(newInterval);
        Collections.sort(result, cmp);

        result = merge(result);

        return result;
    }

    private ArrayList<Interval> merge(ArrayList<Interval> intervals) {
        ArrayList<Interval> result = new ArrayList<>();
        if (intervals == null || intervals.size() == 0) // should never be the case
            return result;
        Interval current = new Interval(intervals.get(0).start, intervals.get(0).end);
        for (int i = 1; i < intervals.size(); i++) {
            if (isOverlapping(current, intervals.get(i))) {
                current.end = Math.max(current.end, intervals.get(i).end);
            } else {
                result.add(current);
                current = new Interval(intervals.get(i).start, intervals.get(i).end);
            }
        }
        // adding the last interval
        result.add(current);
        return result;
    }

    private boolean isOverlapping(Interval a, Interval b) {
        return a.end >= b.start;
    }

    private static class Interval {
        int start;
        int end;

        Interval() {
            start = 0;
            end = 0;
        }

        Interval(int s, int e) {
            start = s;
            end = e;
        }

        @Override
        public String toString() {
            return "[" + start + "," + end + "]";
        }
    }

}
