import java.util.TreeSet;

public class IB_SumOfFibonacciNumbersAlternate {

    public static void main(String[] args) {
        for (int i = 0; i < 20; i++)
            System.out.println(i + " " + new IB_SumOfFibonacciNumbersAlternate().fibsum(i));
    }

    public int fibsum(int number) {
        TreeSet<Integer> fib = new TreeSet<>();
        fib.add(1);
        fib.add(1);
        int a = 1, b = 1;
        while (true) {
            if (b + a > number)
                break;
            int x = a + b;
            fib.add(x);
            a = b;
            b = x;
        }

        int answer = 0;
        while (number != 0) {
            if (fib.contains(number)) {
                answer++;
                break;
            }
            int x = fib.floor(number);
            answer += 1;
            number -= x;
        }

        return answer;
    }
}
