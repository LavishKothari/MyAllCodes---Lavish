package cooling;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main 
{
	public static void main(String[] args)throws IOException 
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine());
		while(t-->0)
		{
			int n=Integer.parseInt(br.readLine());
			int pieWeight[]=new int[n];
			int maxWeight[]=new int[n];
			StringTokenizer stz=new StringTokenizer(br.readLine());
			int i=0;
			while(stz.hasMoreElements())
				pieWeight[i++]=Integer.parseInt(stz.nextToken());
			stz=new StringTokenizer(br.readLine());
			i=0;
			while(stz.hasMoreElements())
				maxWeight[i++]=Integer.parseInt(stz.nextToken());
			Arrays.sort(pieWeight);
			Arrays.sort(maxWeight);
			int answer=0;
			int j=0;
			for(i=0,j=0;j<n;j++)
			{
				if(maxWeight[j]>=pieWeight[i])
				{
					answer++;
					i++;
				}
			}
			System.out.println(answer);
		}

	}

}
