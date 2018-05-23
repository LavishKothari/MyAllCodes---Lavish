package MARCH18B;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class CHEGLOV {

	private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer stz;

	public static void main(String[] args) throws NumberFormatException, IOException {
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			int n = Integer.parseInt(br.readLine());
			List<Integer> hands = new ArrayList<>(n);
			List<Integer> gloves = new ArrayList<>(n);
			stz = new StringTokenizer(br.readLine());
			for(int i=0;i<n;i++) {
				hands.add(Integer.parseInt(stz.nextToken()));
			}
			stz = new StringTokenizer(br.readLine());
			for(int i=0;i<n;i++) {
				gloves.add(Integer.parseInt(stz.nextToken()));
			}
			
			solve(hands,gloves);
		}
	}

	private static void solve(List<Integer> hands, List<Integer> gloves) {
		List<Integer> reverseGloves = new ArrayList<>(hands.size());
		for(int i=hands.size()-1;i>=0;i--) {
			reverseGloves.add(gloves.get(i));
		}
		boolean front = isMatching(hands, gloves);
		boolean back = isMatching(hands, reverseGloves);
		boolean both = front && back;
		if(both)
			System.out.println("both");
		else if(front)
			System.out.println("front");
		else if(back)
			System.out.println("back");
		else 
			System.out.println("none");
	}
	private static boolean isMatching(List<Integer> hands, List<Integer> gloves) {
		for(int i=0;i<hands.size();i++) {
			if(hands.get(i) > gloves.get(i))
				return false;
		}
		return true;
	}
}
