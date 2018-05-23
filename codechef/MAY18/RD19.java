package MAY18;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class RD19 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			int n = Integer.parseInt(br.readLine());
			StringTokenizer stz = new StringTokenizer(br.readLine());
			List<Integer> list = new ArrayList<Integer>(n);
			for(int i=0;i<n;i++)
				list.add(Integer.parseInt(stz.nextToken()));
			long g=list.get(0);
			for(int i=0;i<n;i++) {
				g = gcd(g,list.get(i));
			}
			if(g==1 ) {
				System.out.println(0);
			} else {
				System.out.println(-1);
			}
		}
	}
	private static long gcd(long a, long b) {
		if(b==0)
			return a;
		return gcd(b,a%b);
	}
}
