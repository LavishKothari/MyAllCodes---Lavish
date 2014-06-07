import java.io.*;

class SelectionSort
{
	public static void main(String args[])
	{
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			
			System.out.print("Enter the number of elements that you want to sort : ");
			int n=Integer.parseInt(br.readLine());
			int arr[]=new int[n];
			
			for(int i=0;i<n;i++)
			{
				System.out.print("Enter the element # "+(i+1)+" : ");
				arr[i]=Integer.parseInt(br.readLine());
			}
			
			Selection_Sort(arr);
			System.out.print("Your Sorted array is :\n");
			for(int i=0;i<arr.length;i++)
				System.out.print(arr[i]+" , ");
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
	
	public static void Selection_Sort(int []arr)
	{
		for(int i=0;i<arr.length-1;i++)
		{
			int minIndex=i;
			for(int j=i+1;j<arr.length;j++)
				if(arr[minIndex]>arr[j])
					minIndex=j;
			int temp=arr[minIndex];
			arr[minIndex]=arr[i];
			arr[i]=temp;
		}
	}
}