import java.util.*;

public class PE231 {

    private static final int MAX_N = 20000001;
    private static final BitSet isPrime;
    private static final List<Integer> primes;

    static {
        System.out.println("population started");
        isPrime = new BitSet(MAX_N);
        primes = new ArrayList<>();
        populateIsPrime();
        populatePrimes();
        System.out.println("population done");
    }

    private static void populatePrimes() {
        for (int i = 2; i < MAX_N; i++) {
            if (isPrime.get(i)) {
                primes.add(i);
            }
        }
    }

    private static void populateIsPrime() {
        isPrime.clear();
        isPrime.flip(2, MAX_N);
        for (int i = 2; i * i < MAX_N; i++) {
            if (isPrime.get(i)) {
                for (int j = i * i; j < MAX_N; j += i) {
                    isPrime.set(j, false);
                }
            }
        }
    }

    private static Map<Integer, Integer> getPrimeFactors(int n) {
        Map<Integer, Integer> factors = new HashMap<>();
        int primeCounter = 0;
        while (n != 1) {
            if (isPrime.get(n)) {
                int count = factors.containsKey(n) ? factors.get(n) : 0;
                factors.put(n, count + 1);
                return factors;
            }
            int currentPrime = primes.get(primeCounter);
            while (n % currentPrime == 0) {
                int count = factors.containsKey(currentPrime) ? factors.get(currentPrime) : 0;
                factors.put(currentPrime, count + 1);
                n /= currentPrime;
            }
            primeCounter++;
        }
        return factors;
    }

    private static void union(Map<Integer, Integer> a, Map<Integer, Integer> b) {
        for (Map.Entry<Integer, Integer> entry : b.entrySet()) {
            int countA = a.containsKey(entry.getKey()) ? a.get(entry.getKey()) : 0;
            a.put(entry.getKey(), countA + entry.getValue());
        }
    }

    private static long computeResult(Map<Integer, Integer> map) {
        long result = 0;

        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (entry.getValue() > 0 && isPrime.get(entry.getKey())) {
                result += (long) entry.getKey() * entry.getValue();
            }
        }
        return result;

    }

    public static void main(String[] args) {
        int a = 20000000;
        int b = 15000000;
//        int a = 10;
//        int b = 3;
        Map<Integer, Integer> numerator = new HashMap<>();
        for (int i = b + 1; i <= a; i++) {
            union(numerator, getPrimeFactors(i));
        }
        Map<Integer, Integer> denominator = new HashMap<>();
        for (int i = 2; i <= a - b; i++) {
            union(denominator, getPrimeFactors(i));
        }

        Map<Integer, Integer> result = new HashMap<>();
        for (Map.Entry<Integer, Integer> entry : numerator.entrySet()) {
            int key = entry.getKey();
            if (denominator.containsKey(key)) {
                result.put(key, numerator.get(key) - denominator.get(key));
            } else {
                result.put(key, numerator.get(key));
            }
        }
        System.out.println("answer = " + computeResult(result));
    }


}
