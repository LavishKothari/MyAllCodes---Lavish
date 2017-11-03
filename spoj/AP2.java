import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

class AP2 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            String[] s = br.readLine().split(" ");

            long x = Integer.parseInt(s[0]);
            long y = Integer.parseInt(s[1]);
            long z = Integer.parseInt(s[2]);

            long n = 2 * z / (x + y);
            long d = (y - x) / (n - 5);
            long a = x - 2 * d;

            PrintWriter pw = new PrintWriter(System.out);
            pw.println(n);
            for (long sum = a; sum <= a + (n - 1) * d; sum += d) {
                pw.print(sum + " ");
            }
            pw.println();
            pw.flush();
        }
    }

}
