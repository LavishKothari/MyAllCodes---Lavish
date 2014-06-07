// implementing binary search and sort in Arrays

import java.util.*;
import java.io.*;
class Main
{
	public static void main(String args[])
	{
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			int n=Integer.parseInt(br.readLine());
			int arr[]=new int[n];
			for(int i=0;i<n;i++)
				arr[i]=Integer.parseInt(br.readLine());
			System.out.println(Arrays.binarySearch(arr,5));
			/*
			for(int i=0;i<n;i++)
				System.out.print(arr[i]+"\t");
			*/
		}
		catch(Exception e)
		{
			System.out.println("Exception : "+e);
		}
	}
}
			
						