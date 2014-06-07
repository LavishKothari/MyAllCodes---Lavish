import java.io.*;
class Main
{
	public static void main(String args[])
	{
		try
		{
			System.out.print("Enter the number of elements of the array : ");
			BufferedReader br=new BufferedReader (new InputStreamReader(System.in));

			int n=Integer.parseInt(br.readLine());
			System.out.println("Now Enter the elements of array (in ascending order) :");
			int arr[]=new int[n];
			for(int i=0;i<n;i++)
			{
				arr[i]=Integer.parseInt(br.readLine());
			}
			System.out.println("Enter the search value that you want to search in this array : ");
			int sval=Integer.parseInt(br.readLine());
			System.out.println(Binary_Search(arr,sval));
		}
		catch(Exception e){}
	}
	public static int Binary_Search(int []arr,int sval)
	{
		int first=0;
		int last=arr.length-1;
		int mid;
		
		while(first<=last)
		{					
			mid=(first+last)/2;
			if(arr[mid]==sval)
				return mid;
			if(sval>arr[mid])
				first=mid+1;
			else if(sval<arr[mid])
				last=mid-1;
		}
		return -1;
	}
}