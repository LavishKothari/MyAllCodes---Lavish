package PLCO2018;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class KILLLAZ {
	public final static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private final static int MAX = 10000000;
	private final static int MOD = 1000000007;
	private static long[] fact;

	public static void main(String[] args) throws IOException {
		fact = populateFactorial();
		StringTokenizer stz = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(stz.nextToken());
		int m = Integer.parseInt(stz.nextToken());

		int arr[] = new int[m];
		stz = new StringTokenizer(br.readLine());
		for (int i = 0; i < m; i++) {
			arr[i] = Integer.parseInt(stz.nextToken());
		}
		//int notOccuring = findNotOccuring(n, arr);
		System.out.println(solve(n, m,arr));
	}

//	private static int findNotOccuring(int n, int[] arr) {
//		boolean []flag = new boolean[n+1];
//		for(int i=0;i<arr.length;i++) {
//			flag[arr[i]]=true;
//		}
//		int counter=0;
//		for(int i=0;i<flag.length;i++) {
//			if(!flag[i])
//				counter++;
//		}
//		return counter;
//	}

	private static boolean isSomethingRepeating(int n,int []arr) {
		boolean []flag = new boolean[n+1];
		for(int i=0;i<arr.length;i++) {
			if(flag[arr[i]])
				return true;
			flag[arr[i]]=true;
		}
		return false;
	}
	
	private static long solve(int n, int m,int []arr) {
		if(m>n || isSomethingRepeating(n, arr)) {
			return 0;
		}
		return (fact[n] * (long) inverse((int) fact[m], MOD)) % MOD;
	}
	
	private static long[] populateFactorial() {
		long[] fact = new long[MAX + 1];
		fact[1] = fact[0] = 1;
		for (int i = 2; i <= MAX; i++) {
			fact[i] = (fact[i - 1] * i) % MOD;
		}
		return fact;
	}

	private static long inverse(int a, int m) {
		return power(a, m - 2) % m;
	}

	private static long power(long a, long b) {
		if (b == 0)
			return 1;
		long t = power(a, b / 2);
		if (b % 2 != 0)
			return (((t * t) % MOD) * a) % MOD;
		else
			return (t * t) % MOD;
	}
}
