import java.io.*;

class BubbleSort
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
			
			Bubble_Sort(arr);
			System.out.print("Your Sorted array is :\n");
			for(int i=0;i<arr.length;i++)
				System.out.print(arr[i]+" , ");
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
	
	public static void Bubble_Sort(int []arr)
	{
		for(int i=0;i<arr.length;i++)
		{
			for(int j=0;j<arr.length-i-1;j++)
			{
				if(arr[j]>arr[j+1])
				{
					int tmp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=tmp;
				}
			}
		}
	}
}