package codechef.april19b;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class KLPM {

    public static void main(String[] args) throws IOException {
        int mods[] = {673, 677, 727, 859};
        int bases[] = {877, 877, 877, 877};
        String str = InputUtilities.readString();
        List<Set<Long>> list = new ArrayList<>(mods.length);
        for (int i = 0; i < mods.length; i++) {
            list.add(findGoodAnswer(str, bases[i], mods[i]));
        }
        for (int i = 1; i < list.size(); i++)
            list.get(0).retainAll(list.get(i));
        System.out.println(list.get(0).size());
    }

    private static Set<Long> findGoodAnswer(String str, long base, long mod) {
        StringHashCalculator stringHashCalculator =
                new StringHashCalculator(str, base, mod);
        StringPalindromeCalculator stringPalindromeCalculator =
                new StringPalindromeCalculator(str, stringHashCalculator);

        Set<Long> result = new HashSet<>();
        for (Map.Entry<IntPair, Long> prefix : stringHashCalculator.prefixCache.entrySet()) {
            if (stringHashCalculator.reverseSuffixCache.containsKey(prefix.getValue())) {
                for (IntPair somepair :
                        stringHashCalculator.reverseSuffixCache.get(prefix.getValue())) {
                    IntPair first = prefix.getKey();
                    IntPair second = somepair;
                    // skip complete palindromes
                    if (first.b() >= second.a()) continue;
                    result.add(new PairIntPair(first, second).value);
                    if (first.b() == second.a() - 1) continue;
                    toFirst(first, second, stringPalindromeCalculator, result);
                    toSecond(first, second, stringPalindromeCalculator, result);
                }
            }
        }
        return result;
    }

    public static void toFirst(IntPair first, IntPair second,
                               StringPalindromeCalculator stringPalindromeCalculator,
                               Set<Long> set) {
        int firstIndex = Collections.binarySearch(stringPalindromeCalculator.palins,
                new IntPair(first.b() + 1, first.b() + 1), IntPair.norCmp);
        // firstIndex will always be positive
        int secondIndex = Collections.binarySearch(stringPalindromeCalculator.palins,
                new IntPair(first.b() + 1, second.a() - 1), IntPair.norCmp); ///
        if (secondIndex < 0) {
            secondIndex = -(secondIndex + 1);
            secondIndex--;
        }
        if (secondIndex >= firstIndex) {
            for (int i = firstIndex; i <= secondIndex; i++) {
                IntPair tempPair = new IntPair(first.a(),
                        stringPalindromeCalculator.palins.get(i).b());
                set.add(new PairIntPair(tempPair, second).value);
            }
        }
    }

    public static void toSecond(IntPair first, IntPair second,
                                StringPalindromeCalculator stringPalindromeCalculator,
                                Set<Long> set) {
        int secondIndex = Collections.binarySearch(stringPalindromeCalculator.revPalins,
                new IntPair(second.a() - 1, second.a() - 1), IntPair.revCmp);
        int firstIndex = Collections.binarySearch(stringPalindromeCalculator.revPalins,
                new IntPair(first.b() + 1, second.a() - 1), IntPair.revCmp); ///
        if (firstIndex < 0) {
            firstIndex = -(firstIndex + 1);
        }
        if (secondIndex >= firstIndex) {
            for (int i = firstIndex; i <= secondIndex; i++) {
                IntPair tempPair = new IntPair(
                        stringPalindromeCalculator.revPalins.get(i).a(), second.b());
                set.add(new PairIntPair(first, tempPair).value);
            }
        }
    }

    private static class PairIntPair {
        private final long value;

        public PairIntPair(IntPair a, IntPair b) {
            value = (long) a.a() * (1 << (IntPair.BASE * 3)) +
                    a.b() * (1 << (IntPair.BASE * 2)) +
                    b.a() * (1 << IntPair.BASE) +
                    b.b();
        }

        @Override
        public int hashCode() {
            return Long.hashCode(value);
        }

        @Override
        public boolean equals(Object pip) {
            if (pip == null) return false;
            if (pip instanceof PairIntPair)
                return this.value == ((PairIntPair) pip).value;
            else return false;
        }

        @Override
        public String toString() {
            return value + "";
        }
    }

    private static class IntPair {
        private static final int BASE = 10;
        private static final int POWER = (1 << BASE);
        private static final int MAX_IN_BASE = ((1 << BASE) - 1);
        private static Comparator<IntPair> revCmp = (x, y) -> {
            if (x.b() == y.b()) return Integer.compare(x.a(), y.a());
            return Integer.compare(x.b(), y.b());
        };
        private static Comparator<IntPair> norCmp = (x, y) -> {
            if (x.a() == y.a()) return Integer.compare(x.b(), y.b());
            return Integer.compare(x.a(), y.a());
        };
        private final int value;

        public IntPair(int a, int b) {
            value = a * POWER + b;
        }

        public int a() {
            return value >> BASE;
        }

        public int b() {
            return value & MAX_IN_BASE;
        }

        @Override
        public int hashCode() {
            return value;
        }

        @Override
        public boolean equals(Object o) {
            if (o == null) return false;
            if (o instanceof IntPair) {
                IntPair pair = (IntPair) o;
                return this.value == pair.value;
            } else return false;
        }

        @Override
        public String toString() {
            return "[" + a() + "," + b() + "]";
        }
    }

    private static class StringPalindromeCalculator {
        private final String str;
        private final StringHashCalculator stringHashCalculator;
        private final List<IntPair> palins;
        private final List<IntPair> revPalins;

        public StringPalindromeCalculator(String str,
                                          StringHashCalculator stringHashCalculator) {
            int n = str.length();
            this.str = str;
            this.stringHashCalculator = stringHashCalculator;
            this.palins = new ArrayList<>(n * n);
            for (int i = 0; i < n; i++)
                for (int j = i; j < n; j++)
                    if (isPalindrome(i, j))
                        palins.add(new IntPair(i, j));

            revPalins = new ArrayList<>(palins.size());
            for (int j = 0; j < n; j++)
                for (int i = 0; i <= j; i++)
                    if (isPalindrome(i, j))
                        revPalins.add(new IntPair(i, j));

        }

        private boolean isPalindrome(int i, int j) {
            if (j < i) throw new IllegalArgumentException("i should be <= j");
            if (j - i == 0) return true;
            int fx = i, fy, sx, sy = j;
            sx = fy = (i + j) / 2;
            if ((j - i + 1) % 2 == 0) sx++;

            int counter = 0, checkLength = 10;
            for (int x = fx, y = sy; x <= fy && counter < checkLength; counter++, x++, y--)
                if (str.charAt(x) != str.charAt(y)) return false;
            if (counter != checkLength) return true;
            return stringHashCalculator.getHash(fx, fy) == stringHashCalculator.getReverseHash(sx, sy);
        }

    }

    private static class StringHashCalculator {
        private final long base, mod;
        private final String str;
        private List<Long> prefixHashes;
        private List<Long> suffixHashes;

        private Map<IntPair, Long> prefixCache, suffixCache;
        private Map<Long, List<IntPair>> reversePrefixCache, reverseSuffixCache;

        // O(n^2 log(n)) assuming mod is nearly equal to n
        StringHashCalculator(String str, long base, long mod) {
            this.base = base;
            this.mod = mod;
            this.str = str;
            calPrefixHashes(); // O(n)
            calSuffixHashes(); // O(n)
            // initialize cache
            prefixCache = new HashMap<>();
            suffixCache = new HashMap<>();
            reverseSuffixCache = new HashMap<>();
            reversePrefixCache = new HashMap<>();

            // O(n^2 log(mod))
            for (int i = 0; i < str.length(); i++) {
                for (int j = i; j < str.length(); j++) {
                    IntPair p = new IntPair(i, j);
                    long hash = getHash(i, j);
                    long reverseHash = getReverseHash(i, j);
                    prefixCache.put(p, hash);
                    suffixCache.put(p, reverseHash);
                    reversePrefixCache.putIfAbsent(hash, new ArrayList<>());
                    reverseSuffixCache.putIfAbsent(reverseHash, new ArrayList<>());
                    reversePrefixCache.get(hash).add(p);
                    reverseSuffixCache.get(reverseHash).add(p);
                }
            }
        }

        // a inclusive and b inclusive
        // O(log(mod)) - if mod is nearly equal to n
        // then O(log(n))
        public long getHash(int a, int b) {
            if (a < 0 || b < 0 || a >= str.length() || b >= str.length() || a > b)
                return 0l;
            IntPair p = new IntPair(a, b);
            if (prefixCache.containsKey(p))
                return prefixCache.get(p);
            if (a == 0) {
                return prefixHashes.get(b);
            } else {
                long temp = (prefixHashes.get(b) - prefixHashes.get(a - 1) + mod) % mod;
                long inverse = MathUtilities.power(
                        MathUtilities.power(base, a, mod),
                        mod - 2, mod);
                return ((temp * inverse) % mod + mod) % mod;
            }
        }

        // O(log(base))
        public long getReverseHash(int a, int b) {
            if (a < 0 || b < 0 || a >= str.length() || b >= str.length() || a > b)
                return 0l;
            IntPair p = new IntPair(a, b);
            if (suffixCache.containsKey(p))
                return suffixCache.get(p);
            if (b == str.length() - 1) {
                return suffixHashes.get(a);
            } else {
                long temp = (suffixHashes.get(a) - suffixHashes.get(b + 1) + mod) % mod;
                long inverse = MathUtilities.power(
                        MathUtilities.power(base, str.length() - b - 1, mod),
                        mod - 2, mod);
                return ((temp * inverse) % mod + mod) % mod;
            }
        }

        // O(n)
        private void calSuffixHashes() {
            suffixHashes = new ArrayList<>(str.length());
            long currentHash = 0l, power = 1l;
            for (int i = str.length() - 1; i >= 0; i--) {
                currentHash = (currentHash + str.charAt(i) * power) % mod;
                power = (power * base) % mod;
                suffixHashes.add(currentHash);
            }
            Collections.reverse(suffixHashes);
        }

        // O(n)
        private void calPrefixHashes() {
            prefixHashes = new ArrayList<>(str.length());
            long currentHash = 0l, power = 1l;
            for (int i = 0; i < str.length(); i++) {
                currentHash = (currentHash + str.charAt(i) * power) % mod;
                power = (power * base) % mod;
                prefixHashes.add(currentHash);
            }
        }

    }

    private static class InputUtilities {
        private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        private InputUtilities() {
        }

        public static String readString() throws IOException {
            return br.readLine();
        }
    }

    private static class MathUtilities {

        private static int CACHE_SIZE = 1000;
        private static long[][] power;
        private static long MOD = 877l;

        static {
            power = new long[CACHE_SIZE][CACHE_SIZE];
            for (int i = 1; i < CACHE_SIZE; i++) {
                long p = 1;
                power[i][0] = 1;
                for (int j = 1; j < CACHE_SIZE; j++) {
                    p = (p * i) % MOD;
                    power[i][j] = p;
                }
            }
        }

        private MathUtilities() {
        }

        public static long power(long a, long b, long mod) {
            if (mod == MOD && a < CACHE_SIZE && b < CACHE_SIZE)
                return power[(int) a][(int) b];

            if (a == 0) return 0l;
            if (a == 1 || b == 0) return 1l;
            if (b == 1) return a % mod;
            long t = power(a, b >> 1, mod);
            if (b % 2 == 0) return (t * t) % mod;
            return ((t * t) % mod * a) % mod;
        }
    }

}
