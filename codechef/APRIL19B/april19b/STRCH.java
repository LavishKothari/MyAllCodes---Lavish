package codechef.april19b;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class STRCH {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer stz;

    private static int readInt() throws Exception {
        return Integer.parseInt(br.readLine());
    }

    public static void main(String[] args) throws Exception {
        int t = readInt();
        while (t-- > 0) {
            readInt();
            stz = new StringTokenizer(br.readLine());
            String str = stz.nextToken();
            char ch = stz.nextToken().charAt(0);
            System.out.println(findAnswer(str, ch));
        }
    }

    private static long findAnswer(String s, char ch) {
        long answer = 0, prev = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ch) {
                answer += (i - prev + 1) * (s.length() - i);
                prev = i + 1;
            }
        }
        return answer;
    }

}
