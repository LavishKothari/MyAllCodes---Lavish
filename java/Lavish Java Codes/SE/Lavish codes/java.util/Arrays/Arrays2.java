/*
	illustration of 
		Arrays.sort(int[]arr,int start,int end) method	
	
	the above function will sort the array
	starting from the index "start" 
	and will sort the array till the index "end-1"
*/

import java.util.Arrays;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Main
{
	public static void main(String args[])
	{
		try
		{
			
			System.out.println("Enter the number of elements of the array : ");
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			int n=Integer.parseInt(br.readLine());
			int arr[]=new int[n];
			
			System.out.println("Enter the data of the array : ");
			
			for(int i=0;i<n;i++)
				arr[i]=Integer.parseInt(br.readLine());
				
			System.out.print("Enter the index from where you want to start sorting  : ");
			int a=Integer.parseInt(br.readLine());
			System.out.print("Enter the index till which you want to sort the array : ");
			int b=Integer.parseInt(br.readLine());
			
			Arrays.sort(arr,a,b+1);
			printArray(arr);
		}
		catch(IOException e) 
		{
			System.out.println(e);
		}
		catch(NumberFormatException e) // due to Integer.parseInt()
		{	
			System.out.println(e);
		}
	}
	
	public static void printArray(int[]a)
	{
		System.out.println("\nyour array is as follows :");
		for(int i=0;i<a.length;i++)
			System.out.println(a[i]);
	}
}