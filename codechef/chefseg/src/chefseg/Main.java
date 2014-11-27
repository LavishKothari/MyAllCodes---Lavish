package chefseg;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
	public static void main(String args[]) throws IOException
	{
	    long t,x,q,p;
	    long k;

		double answer;
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		t=Long.parseLong(br.readLine());
		for(int i=0;i<t;i++)
		{
			StringTokenizer stz=new StringTokenizer(br.readLine());
			x=Long.parseLong(stz.nextToken());
			k=Long.parseLong(stz.nextToken());
			
			p=(long)(Math.log10(k)/Math.log10(2))+1;
		    q=k-(long)Math.pow(2,p-1)+1;
		    answer=(x/Math.pow(2,p))*(2*q-1);
		    System.out.format("%f\n", answer);
		    //String ans=String.format("%f", answer+"");
		    //System.out.println(ans);
		}
	}
}
