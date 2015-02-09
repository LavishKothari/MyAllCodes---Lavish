package prgift;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int t;
		t=Integer.parseInt(br.readLine());
		for(int i=0;i<t;i++)
		{
			int n,k;
			StringTokenizer stz=new StringTokenizer(br.readLine());
			n=Integer.parseInt(stz.nextToken());
			k=Integer.parseInt(stz.nextToken());
			
			int arr[]=new int[n];
			stz=new StringTokenizer(br.readLine());
			
			int countereven=0,counterodd=0;
			for(int j=0;j<n;j++)
			{
				arr[j]=Integer.parseInt(stz.nextToken());
				if(arr[j]%2==0)
					countereven++;
				else
					counterodd++;
			}
			if(k==0 && counterodd>0)
				System.out.println("YES");
			else if(k==0 && counterodd==0)
				System.out.println("NO");
			else
			{
				if(countereven>=k)
					System.out.println("YES");
				else
					System.out.println("NO");
			}
		}
	}
}
