package retpo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String args[]) throws NumberFormatException, IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine());
		for(int i=0;i<t;i++)
		{
			StringTokenizer stz=new StringTokenizer(br.readLine());
			long x=Long.parseLong(stz.nextToken());
			long y=Long.parseLong(stz.nextToken());
			
			System.out.println(findAnswer(x,y));
		}
	}
	
	private static long findAnswer(long x,long y)
	{
		if(y==0)
		{
			x=Math.abs(x);
		}
		long absx=Math.abs(x);
		long absy=Math.abs(y);
		long answer;
		if(absx==0 && absy==0)
			answer=0;
		else if(x>0)
			answer=Math.min(absx,absy)*2;
		else
		{
			if(y==0)
			{
				answer=2+absx;
				//return answer;
			}
			else
				answer=Math.min(absx,absy)*2;
		}
		
		if(absx!=absy)
		{
			answer+=(Math.abs(absx-absy)/2)*4;
			
			if(absx>absy)
			{
				if(Math.abs(absx-absy)%2!=0)
					answer+=3;
			}
			else
			{
				if(Math.abs(absx-absy)%2!=0)
				{
					answer+=1;
				}
			}
		}
		return answer;
	}
}
