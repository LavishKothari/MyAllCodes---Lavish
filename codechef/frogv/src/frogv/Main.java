package frogv;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main 
{
	static int n,p,k;
	static int []arr;
	
	public static void main(String args[]) throws NumberFormatException, IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stz=new StringTokenizer(br.readLine());
		n=Integer.parseInt(stz.nextToken());
		k=Integer.parseInt(stz.nextToken());
		p=Integer.parseInt(stz.nextToken());
		
		stz=new StringTokenizer(br.readLine());
		
		arr=new int[n];
		
		for(int i=0;i<n;i++)
		{
			arr[i]=Integer.parseInt((String) stz.nextElement());
		}
		
		for(int i=0;i<p;i++)
		{
			StringTokenizer s=new StringTokenizer(br.readLine());
			int a=Integer.parseInt((String)s.nextElement());
			int b=Integer.parseInt((String)s.nextElement());
			
			printAnswer(a-1,b-1);
		}
		
	}
	
	public static void printAnswer(int a,int b)
	{
		if(a>b)
		{
			int temp=a;
			a=b;
			b=temp;
		}
		while(true)
		{
			if(a==b)
			{
				System.out.println("Yes");
				return;
			}
			a=findNext(a);
			if(a==-1)
			{
				System.out.println("No");
				return;
			}
		}
	}
	public static int findNext(int a)
	{
		int searchval;
	
		for(int z=0;z<=k;z++)
		{
			searchval=arr[a]+z;
			for(int i=0;i<arr.length;i++)
				if(arr[i]==searchval && i!=a)
					return i;
		}
		return -1;
	}
}