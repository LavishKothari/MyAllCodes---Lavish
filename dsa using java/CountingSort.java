// applicable only for non-negative Integers
import java.io.*;
class Main
{
	public static void main(String args[])throws IOException 
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Enter the number of elements that you want to sort : ");
		int n=Integer.parseInt(br.readLine());
		System.out.println("Enter the data of Array that you want to sort : ");
		System.out.println("(The data elements of the array should be non-negative integers...)");
		int arr[]=new int[n];
		for(int i=0;i<n;i++)
		{
			System.out.print("Enter the element # "+(i+1)+" : ");
			arr[i]=Integer.parseInt(br.readLine());
		}
		arr=countingSort(arr);
		for(int i=0;i<arr.length;i++)
			System.out.print(arr[i]+" , ");
	}
	
	public static int[] countingSort(int[]arr)
	{
		int finalAns[]=new int[arr.length];
		int max=findMax(arr);
		int ans[]=new int[max+1];
		
		/*ans[j] now contains the number of elements equal to j*/
		for(int i=0;i<arr.length;i++)
			ans[arr[i]]++;
		
		/*c[j] now contains the number of elements less than or equal to j*/
		for(int i=1;i<ans.length;i++)
			ans[i]+=ans[i-1];
		
		/*preparing the finalAns array*/
		for(int i=0;i<arr.length;i++)
			finalAns[--ans[arr[i]]]=arr[i];
		
		return finalAns;
	}
	public static int findMax(int[]arr)
	{
		int max=Integer.MIN_VALUE;
		for(int i=0;i<arr.length;i++)
			if(arr[i]>max)
				max=arr[i];
		return max;
	}
}