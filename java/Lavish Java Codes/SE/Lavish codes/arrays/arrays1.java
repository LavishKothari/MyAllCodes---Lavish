// program illustraing 2-d arrays in java
// using for-each loop for printing 2-d arrays
import java.io.*;

class Main
{
	public static void main(String[]args)
	{
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			System.out.println("enter the rows and columns of matrix : ");
			int r=Integer.parseInt(br.readLine());
			int c=Integer.parseInt(br.readLine());
			int arr[][]=new int[r][c];
			for(int i=0;i<r;i++)
				for(int j=0;j<c;j++)
					arr[i][j]=Integer.parseInt(br.readLine());
			/*
			normally printing the elements of 2-d array using for loop	
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
					System.out.print(arr[i][j]+"\t");
				System.out.println();
			}
			*/
			//using for-each loop
			for(int a[]:arr)
			{
				for(int b:a)
					System.out.print(b+"\t");
				System.out.println();
			}
		}
		catch(IOException e)
		{	
			System.out.println("Exception = "+e);
		}
	}
}			