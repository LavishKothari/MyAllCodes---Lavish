import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class LeetCode56 {


    public List<Interval> merge(List<Interval> intervals) {
        if (intervals.size() == 0)
            return Collections.<Interval>emptyList();
        Collections.sort(intervals, (i1, i2) -> {
            if (i1.start < i2.start) return -1;
            else if (i1.start > i2.start) return 1;
            else if (i1.end < i2.end) return -1;
            else if (i1.end > i2.end) return 1;
            else return 0;
        });
        List<Interval> result = new ArrayList<>();
        // constructing new object is important to avoid tampering the original object
        Interval current = new Interval(intervals.get(0).start, intervals.get(0).end);
        for (int i = 1; i < intervals.size(); i++) {
            if (isOverlapping(current, intervals.get(i))) {
                current.end = Math.max(intervals.get(i).end, current.end);
            } else {
                result.add(current);
                current = new Interval(intervals.get(i).start, intervals.get(i).end);
            }
        }
        result.add(current);
        return result;
    }

    // this method assumes that the interval `a` is smaller than interval `b`
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
