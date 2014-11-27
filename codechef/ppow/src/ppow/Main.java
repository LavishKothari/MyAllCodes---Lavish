package ppow;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args)throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine());
		//int t=36000;
		int ans[][]=new int[10][4001];
		System.out.println("Started");
		for(int a=2;a<=9;a++)
		{
			System.out.println(""+a);
			BigInteger pa=new BigInteger(a+"");
			for(int b=1;b<4001;b++)
			{
				System.out.println(b);
				BigInteger pb=new BigInteger(b+"");
				pa=pa.multiply(pb);
				int answer=0;
				char ch[]=pa.toString().toCharArray();
				int j,k;
				for(j=0,k=ch.length-1;j<k;j++,k--)
					answer+=ch[j]+ch[k]-2*'0';
				if(j==k)// means length is odd
					answer+=ch[j]-'0';
				ans[a][b]=answer;
			}
		}
		System.out.println("finished");
		for(int i=0;i<t;i++)
		{
			StringTokenizer stz=new StringTokenizer(br.readLine());
			int a=Integer.parseInt(stz.nextToken());
			int b=Integer.parseInt(stz.nextToken());
			System.out.println("Case "+(i+1)+": "+ans[a][b]);
		}
		
	}

}
