import java.util.*;

public class LeetCode146 {
    public static void main(String[] args) {
        LRUCache lruCache = new LRUCache(1);
        lruCache.put(2, 1);
        lruCache.get(2);
        lruCache.put(3, 2);
        lruCache.get(2);
        lruCache.get(3);
    }

}

class SpecialList {
    static class Node {
        int value;
        Node prev, next;

        public Node(int value) {
            this.value = value;
        }
    }

    Node front;
    Node last;

    public SpecialList() {
        this.front = this.last = null;
    }

    public void addLast(Node nn) {
        if (front == null) {
            front = last = nn;
        } else {
            last.next = nn;
            last.next.prev = last;
            last = nn;
        }
    }

    public void remove(Node node) {
        Node back = node.prev;
        Node fwd = node.next;

        if (back != null) {
            back.next = fwd;
        }
        if (fwd != null) {
            fwd.prev = back;
        }

        if (last == node) {
            last = back;
        }
        if (front == node) {
            front = fwd;
        }
    }

    public Node removeFirst() {
        Node tempFirst = front;
        front = front.next;
        if (front != null)
            front.prev = null;
        return tempFirst;
    }
}


class LRUCache {
    Map<Integer, Integer> mf = new HashMap<>(); // key, timestamp
    // Map<Integer, Integer> mb = new HashMap<>(); // timestamp, key
    Map<Integer, SpecialList.Node> mbb = new HashMap<>(); // timestamp, node
    Map<Integer, Integer> mv = new HashMap<>(); // key, value
    SpecialList sl = new SpecialList();

    int counter = 0; // timestamp
    int capacity;

    public LRUCache(int capacity) {
        this.capacity = capacity;
    }

    public int get(int key) {
        if (!mv.containsKey(key)) {
            return -1;
        }
        counter++;
        int prevTS = mf.get(key);
        mf.put(key, counter);

        SpecialList.Node prevNode = mbb.get(prevTS);
        mbb.remove(prevTS);
        sl.remove(prevNode);

        // mb.remove(prevTS);
        // mb.put(counter, key); // add at last in SpecialList

        SpecialList.Node nn = new SpecialList.Node(key);
        mbb.put(counter, nn);
        sl.addLast(nn);

        return mv.get(key);
    }

    public void put(int key, int value) {
        if (mv.containsKey(key)) {
            get(key); // I don’t care about the return value
            mv.put(key, value);
            return;
        }
        counter++;
        if (mv.size() == capacity) {
            // the map is full and you need to evict the oldest
            // oldest -> key which has the lowest counter
            SpecialList.Node firstNode = sl.removeFirst();
            int removeKey = firstNode.value;
            int removeTS = mf.get(removeKey);
            mf.remove(removeKey);
            mbb.remove(removeTS);
            mv.remove(removeKey);
            // return;
        }

        mv.put(key, value);
        mf.put(key, counter);
        SpecialList.Node nn = new SpecialList.Node(key);
        mbb.put(counter, nn);
        sl.addLast(nn);
        // mb.put(counter, key); // add at last in special list
    }
}
