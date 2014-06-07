import java.io.*;

class Main
{
	public static void main(String[]args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		System.out.print("Enter the number of elements that you want to sort : ");
		int n=Integer.parseInt(br.readLine());
		int arr[]=new int[n];
		System.out.println("Enter the data of the array : ");
		for(int i=0;i<n;i++)
		{
			System.out.print("Enter the data item # "+(i+1)+" : ");
			arr[i]=Integer.parseInt(br.readLine());
		}
		quickSort(arr,0,arr.length-1);
		for(int i=0;i<n;i++)
			System.out.print(arr[i]+" , ");
	}
	public static void quickSort(int []arr,int p,int r)
	{
		if(p<r)
		{
			int q=partition(arr,p,r);
			quickSort(arr,p,q-1);
			quickSort(arr,q+1,r);
		}
	}
	public static int partition(int []arr,int p,int r)
	{
		int x=arr[r];
		int i=p-1;
		for(int j=p;j<r;j++)
		{
			if(arr[j]<x)
			{
				i++;
				int tmp=arr[j];
				arr[j]=arr[i];
				arr[i]=tmp;
			}
		}
		int tmp=arr[i+1];
		arr[i+1]=arr[r];
		arr[r]=tmp;
		return (i+1);
	}
}