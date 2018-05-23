package MAY18;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class XORAGN {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			int n = Integer.parseInt(br.readLine());
			StringTokenizer stz = new StringTokenizer(br.readLine());
			int answer = 0;
			for (int i = 0; i < n; i++) {
				int x = Integer.parseInt(stz.nextToken());
				answer = answer ^ (2 * x);
			}
			System.out.println(answer);
		}
	}

}
