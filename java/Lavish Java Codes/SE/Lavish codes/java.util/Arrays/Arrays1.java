/*
	illustration of 
		Arrays.sort() method
		Arrays.binarySearch() method
	both Arrays.sort() and Arrays.binarySearch() 
	are static methods.
	
	before applying binarySearch() method on this array, 
	you should first have the array sorted in non descending order.
	
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
				
			Arrays.sort(arr);
			printArray(arr);
			
			System.out.println("the index of 5 in the Array is : "+Arrays.binarySearch(arr,5));
		}
		catch(IOException e)
		{
			System.out.println(e);
		}
		catch(NumberFormatException e)
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