import java.util.*;

public class LeetCode149 {
    public static void main(String[] args) {
        System.out.println(new Solution().maxPoints( // 3
                new Point[]{new Point(1, 1),
                        new Point(2, 2),
                        new Point(3, 3)}));

        System.out.println(new Solution().maxPoints( // 4
                new Point[]{new Point(1, 1),
                        new Point(3, 2),
                        new Point(5, 3),
                        new Point(4, 1),
                        new Point(2, 3),
                        new Point(1, 4)
                }
        ));
        System.out.println(new Solution().maxPoints( // 2
                new Point[]{new Point(0, 0),
                        new Point(0, 0)
                }
        ));
        System.out.println(new Solution().maxPoints( // 3
                new Point[]{new Point(0, 0),
                        new Point(-1, -1),
                        new Point(2, 2)
                }
        ));
        System.out.println(new Solution().maxPoints( // 6
                new Point[]{
                        new Point(1, 1),
                        new Point(1, 1),
                        new Point(1, 1),
                        new Point(2, 3),
                        new Point(2, 3),
                        new Point(2, 3),
                        new Point(3, 3),
                        new Point(3, 3)
                }
        ));

    }
}

class Point {
    int x;
    int y;

    Point() {
        x = 0;
        y = 0;
    }

    Point(int a, int b) {
        x = a;
        y = b;
    }

    @Override
    public String toString() {
        return "[" + x + "," + y + "]";
    }
}

// ax+by+c=0;
class Line {
    private int a, b, c;

    Line(Point p1, Point p2) {
        int x1 = p1.x;
        int y1 = p1.y;
        int x2 = p2.x;
        int y2 = p2.y;
        a = y2 - y1;
        b = x1 - x2;
        c = y1 * (x2 - x1) - x1 * (y2 - y1);
        rationalize();
    }

    private int gcd(int x, int y) {
        if (x == 0) return y;
        if (y == 0) return x;
        return gcd(y, x % y);
    }

    private int commonFactor(int x, int y, int z) {
        return gcd(gcd(x, y), z);
    }

    private void rationalize() {
        if (a < 0) {
            a = -a;
            b = -b;
            c = -c;
        }
        int cf = commonFactor(Math.abs(a), Math.abs(b), Math.abs(c));
        if (cf == 0 || cf == 1)
            return;
        a /= cf;
        b /= cf;
        c /= cf;

    }

    @Override
    public boolean equals(Object line) {
        if (line == null)
            return false;
        if (!(line instanceof Line))
            return false;
        Line lineObj = (Line) line;
        return lineObj.a == a && lineObj.b == b && lineObj.c == c;
    }

    @Override
    public int hashCode() {
        // return Objects.hashCode(a,b,c);
        return Arrays.hashCode(new int[]{a, b, c});
    }

    @Override
    public String toString() {
        return "[" + a + "," + b + "," + c + "]";
    }
}

// edge case: if the points array contains only one point
class Solution {
    public int maxPoints(Point[] points) {
        if (points.length <= 1)
            return points.length;
        Comparator<Point> pointComparator = (p1, p2) -> {
            if (p1.x < p2.x) return -1;
            else if (p1.x > p2.x) return 1;
            else if (p1.y < p2.y) return -1;
            else if (p1.y > p2.y) return 1;
            else return 0;
        };
        Map<Line, Set<Point>> lineMap = new HashMap<>();
        Map<Point, Integer> pointMap = new TreeMap<>(pointComparator);
        for (int i = 0; i < points.length; i++) {
            int count = pointMap.containsKey(points[i]) ? pointMap.get(points[i]) : 0;
            pointMap.put(points[i], count + 1);
            for (int j = i + 1; j < points.length; j++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y)
                    continue;
                Line cl = new Line(points[i], points[j]);
                lineMap.putIfAbsent(cl, new TreeSet<>(pointComparator));
                lineMap.get(cl).add(points[i]);
                lineMap.get(cl).add(points[j]);
            }
        }
        int max = 1;
        for (Map.Entry<Point, Integer> entry : pointMap.entrySet()) {
            if (entry.getValue() > max)
                max = entry.getValue();
        }
        for (Map.Entry<Line, Set<Point>> entry : lineMap.entrySet()) {
            int counter = 0;
            for (Point p : entry.getValue()) {
                counter += pointMap.get(p);
            }
            if (counter > max) {
                max = counter;
            }

        }

        return max;
    }
}

