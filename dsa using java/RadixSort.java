// applicable only for non-negative Integers
import java.io.*;
class Main
{
	static int d;
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
		arr=radixSort(arr);
		for(int i=0;i<arr.length;i++)
			System.out.print(arr[i]+" , ");
	}
	
	public static int[] radixSort(int[]arr)
	{
		/*finding the number of digits that the maximum element in the array will have.*/
		d=(findMax(arr)+"").length();
		for(int i=d;i>=1;i--)
			arr=stableSort(arr,i);
		return arr;
	}
	
	public static int findMax(int[]arr)
	{
		int max=Integer.MIN_VALUE;
		for(int i=0;i<arr.length;i++)
			if(arr[i]>max)
				max=arr[i];
		return max;
	}
	
	public static int digitAt(int n,int i)
	{
		String str=new String("");
		for(int j=0;j<d-(n+"").length();j++)
			str+="0";
		if(i>=1 && i<=(str+n).length())
			return Integer.parseInt(""+((str+n).charAt(i-1)));
		return 0;
	}
	
	public static int[] stableSort(int[]arr,int n)
	{
		/* a revised implementation of CountingSort */
		int finalAns[]=new int[arr.length];
		int ans[]=new int[10];
		
		for(int i=0;i<arr.length;i++)
			ans[digitAt(arr[i],n)]++;
		/*ans[j] now contains the number of elements equal to j*/
		
		for(int i=1;i<ans.length;i++)
			ans[i]+=ans[i-1];
		/*c[j] now contains the number of elements less than or equal to j*/
		
		/*preparing the finalAns array*/
		for(int i=arr.length-1;i>=0;i--)
			finalAns[--ans[digitAt(arr[i],n)]]=arr[i];
		
		return finalAns;
	}
	
}