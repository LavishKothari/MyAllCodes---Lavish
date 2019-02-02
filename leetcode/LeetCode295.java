import java.util.PriorityQueue;

class LeetCode295 {
    public static void main(String[] args) {
        MedianFinder mf = new MedianFinder();
        mf.addNum(1);
        System.out.println(mf.findMedian()); // 1
        mf.addNum(2);
        System.out.println(mf.findMedian());// -> 1.5
        mf.addNum(3);
        System.out.println(mf.findMedian());// -> 2
        mf.addNum(4);
        System.out.println(mf.findMedian()); /// 2.5
    }
}

class MedianFinder {

    private final PriorityQueue<Integer> left;
    private final PriorityQueue<Integer> right;

    /**
     * initialize your data structure here.
     */
    public MedianFinder() {
        left = new PriorityQueue<>((a, b) -> b - a); // max-heap
        right = new PriorityQueue<>(); // min-heap
    }

    // time complexity - O(log(n))
    public void addNum(int num) {
        if (left.size() == 0 && right.size() == 0) {
            left.offer(num);
            return;
        }

        if (num < findMedian())
            left.offer(num);
        else right.offer(num);

        int sizeDiff = Math.abs(left.size() - right.size());
        if (sizeDiff > 1) {
            if (left.size() > right.size()) {
                int shifted = left.poll();
                right.offer(shifted);
            } else {
                int shifted = right.poll();
                left.offer(shifted);
            }
        }

    }


    // takes O(1)
    public double findMedian() {
        if (left.size() == right.size()) {
            return (left.peek() + right.peek()) / 2.0;
        } else if (left.size() > right.size()) {
            return left.peek();
        } else return right.peek();
    }
}


