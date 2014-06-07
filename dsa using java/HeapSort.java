/*
	Heap Sort
*/
import java.io.*;
class Main
{
	public static int heapLength;
	public static void main(String args[])throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		System.out.print("Enter the number of Elements that you want to sort : ");
		int n=Integer.parseInt(br.readLine());
		System.out.println("Enter the Elements that you want to sort : ");
		
		int arr[]=new int[n];
		
		for(int i=0;i<n;i++)
		{
			System.out.print("Enter the Element # "+(i+1)+" : ");
			arr[i]=Integer.parseInt(br.readLine());
		}
		heapLength=n;
		heapSort(arr);
		
		System.out.println("Your sorted elements are : ");
		for(int i=0;i<arr.length;i++)
			System.out.print(arr[i]+" , ");
	}

	public static int getParentIndex(int n)
	{
		return (n/2);
	}
	public static int getLeftChildIndex(int n)
	{
		return n*2;
	}
	public static int getRightChildIndex(int n)
	{
		return n*2+1;
	}
	
	public static void maxHeapify(int []arr,int i)
	{
		int l=getLeftChildIndex(i+1)-1; // our array is zero indexed array...
		int r=getRightChildIndex(i+1)-1;
		int largest,tmp;
		if(l<=heapLength-1 && arr[l]>arr[i])
			largest=l;
		else
			largest=i;
			
		if(r<=heapLength-1 && arr[r]>arr[largest])
			largest=r;
		
		// exchange arr[i] and arr[largest]
		if(largest!=i)
		{
			tmp=arr[i];
			arr[i]=arr[largest];
			arr[largest]=tmp;
			
			maxHeapify(arr,largest);
		}
	}
	
	public static void buildMaxHeap(int []arr)
	{
		for(int i=getParentIndex(arr.length)-1;i>=0;i--)
			maxHeapify(arr,i);
	}
	
	public static void heapSort(int[]arr)
	{
		buildMaxHeap(arr);
		int tmp;
		for(int i=arr.length-1;i>=1;i--)
		{
			tmp=arr[0];
			arr[0]=arr[i];
			arr[i]=tmp;
			
			heapLength--;
			maxHeapify(arr,0);
		}
	}	
}