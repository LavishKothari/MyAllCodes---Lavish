// arrays in java --> how to declare arrays in java and use them
// printing arrays using for each loop
// IOException and ArrayIndexOutOfBoundsException 

import java.io.*;

class Main
{
	public static void main(String[]args)	
	{
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			int arr[]=new int[5];
			for(int i=0;i<5;i++)
				arr[i]=Integer.parseInt(br.readLine());
			
			System.out.println("the data of array is : ");
			//using for each loop
			for(int i : arr)
				System.out.println(i);

		}	
		catch(IOException e)
		{
			System.out.println("Exception : "+e);
		}
		catch(ArrayIndexOutOfBoundsException e)
		{
			System.out.println("Exception : "+e);
		}
	}
}