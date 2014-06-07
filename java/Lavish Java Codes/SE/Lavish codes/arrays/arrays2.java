//jagged array

import java.io.*;

class Main
{
	public static void main(String []args)
	{
		try
		{
	
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			System.out.print("enter a number : ");
			int n=Integer.parseInt(br.readLine());

			int arr[][]=new int[n][];
			for(int i=0;i<n;i++)
				arr[i]=new int[i+1];

			for(int i=0;i<n;i++)
				for(int j=0;j<=i;j++)
					arr[i][j]=Integer.parseInt(br.readLine());

			System.out.println("Your jagged array is : ");

			for(int i=0;i<n;i++)
			{
				for(int j=0;j<=i;j++)
					System.out.print(arr[i][j]+"\t");
				System.out.println();
			}
		
		}
		catch(Exception e)
		{
			System.out.println("Exception : "+e);	
		}
	}
}
		
						 