package com.codechef.march19b;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class INTERLEA {

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        List<String> list = new ArrayList<>(n);
        for (int i = 0; i < n; i++) list.add(br.readLine());

        String result = findAnswer(list);
        System.out.println(result);
    }

    private static String findAnswer(List<String> list) {
        MyList<CharacterIndex> result = new MyList<>();

        for (int i = 0; i < list.size(); i++) {
            merge(result, getCharacterIndexList(list.get(i), i + 1));
        }

        System.out.println(result);
        StringBuilder sb = new StringBuilder();
        MyListNode<CharacterIndex> cn = result.head;
        while (cn != null) {
            sb.append(cn.val.index);
            sb.append(" ");
            cn = cn.next;
        }
        return sb.toString();
    }

    private static List<CharacterIndex> getCharacterIndexList(String s, int index) {
        List<CharacterIndex> list = new ArrayList<>(s.length());
        for (char c : s.toCharArray()) {
            list.add(new CharacterIndex(c, index));
        }
        return list;
    }

    private static void merge(MyList<CharacterIndex> a, List<CharacterIndex> b) {
        int counter = 0;
        MyListNode<CharacterIndex> cn = a.head;
        int missed = 0;
        final int missedThreshold = 10;
        while (cn != null) {
            if (counter < b.size()) {
                CharacterIndex ci = b.get(counter);
                if (Math.abs(cn.val.c - ci.c) <= 0 ||
                        (cn.next != null && ci.c >= cn.val.c && ci.c <= cn.next.val.c) ||
                        (cn.next != null && ci.c <= cn.val.c && ci.c >= cn.next.val.c)

                ) {
                    a.add(cn, b.get(counter++));
                } else {
                    missed++;
                    if (missed == missedThreshold) {
                        missed = 0;
                        a.add(cn, b.get(counter++));
                    }
                }
            } else break;
            cn = cn.next;
        }
        for (int i = counter; i < b.size(); i++) {
            a.add(b.get(i));
        }
    }

    private static class CharacterIndex {
        private final char c;
        private final int index;
        private int count;

        public CharacterIndex(char c, int index) {
            this.count = 1;
            this.c = c;
            this.index = index;
        }

        @Override
        public String toString() {
            return "(" + c + "," + index + ")";
        }
    }

    private static class MyList<T> {
        private MyListNode<T> head;
        private MyListNode<T> tail;

        public MyList() {
        }

        public void add(T val) {
            MyListNode<T> node = new MyListNode<>(val);
            if (head == null) {
                head = tail = node;
                return;
            }

            node.prev = tail;
            tail.next = node;
            tail = node;
        }

        public void add(MyListNode<T> node, T val) {
            if (node.next == null && node != tail)
                throw new IllegalStateException("tail is not maintained properly");
            if (node == null)
                throw new IllegalArgumentException("node can't be null");
            if (node == tail) add(val); // adding at the end

            MyListNode<T> nn = new MyListNode<>(val);
            MyListNode<T> next = node.next;
            nn.next = next;
            nn.prev = node;
            node.next = nn;
            next.prev = nn;
        }

        @Override
        public String toString() {
            StringBuilder br = new StringBuilder();

            MyListNode<T> cn = head;
            while (cn != null) {
                br.append(cn);
                cn = cn.next;
            }

            return br.toString();
        }
    }

    private static class MyListNode<T> {
        private final T val;
        private MyListNode<T> next;
        private MyListNode<T> prev;

        public MyListNode(T val) {
            this.val = val;
        }

        public void isolate() {
            next = prev = null;
        }

        @Override
        public String toString() {
            System.out.println(val + " " + (prev != null ? prev.val : "null") + " " + (next != null ? next.val : "null"));
            return "{" + val + " prev:" + prev == null ? "null" : prev + " next:" + next == null ? "null" : next + "}";
        }
    }

}