import java.io.*;
class InsertionSort
{
	public static void main(String []ars)
	{
		try
		{
			BufferedReader br=new BufferedReader (new InputStreamReader (System.in));
			System.out.print("Enter the number of elements that you want to sort : ");
			int n=Integer.parseInt(br.readLine());
			int arr[]=new int [n];
			System.out.println("enter the data of the array : ");
			for(int i=0;i<n;i++)
			{
				System.out.print("enter the element # : "+(i+1)+" : ");
				arr[i]=Integer.parseInt(br.readLine());
			}
			
			Insertion_Sort(arr);
			
			System.out.println("your sorted array is : ");
			
			for(int i=0;i<arr.length;i++)
				System.out.print(arr[i]+" , ");
		}
		catch(IOException ioe){System.out.println(ioe.getMessage());}
		catch(NumberFormatException ne){System.out.println(ne.getMessage());}
	}
	public static void Insertion_Sort(int []arr)
	{
		for(int i=1;i<arr.length;i++)
		{
			int key=arr[i],j;
			for(j=i-1;j>=0 && key<arr[j];j--)
				arr[j+1]=arr[j];	
			arr[j+1]=key;
		}
	}
}