import java.io.*;

class MergeSort
{
	public static void main(String args[])
	{
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			System.out.print("Enter the number of elements in the array : ");
			
			int n=Integer.parseInt(br.readLine());
			int arr[]=new int[n];
			for(int i=0;i<n;i++)
			{
				System.out.print("Enter element number "+(i+1)+" : ");
				arr[i]=Integer.parseInt(br.readLine());
			}
			
			Merge_Sort(arr,0,n-1);
		
			System.out.println("\nYour sorted array is : ");
			for(int i=0;i<n;i++)
				System.out.println(arr[i]);
		}
		catch(Exception e){System.out.println(e.getMessage());}
	}
	
	public static void Merge(int []arr,int p,int q,int r)
	{
		int n1,n2;
		n1=q-p+1;
		n2=r-q;
		int L[]=new int[n1+1];
		int R[]=new int[n2+1];
		int i;
		for(i=0;i<n1;i++)
			L[i]=arr[p+i];
		L[i]=Integer.MAX_VALUE; // setting the sentinel
		
		for(i=0;i<n2;i++)
			R[i]=arr[q+1+i];	
		R[i]=Integer.MAX_VALUE; // setting the sentinel
		
		int counterL,counterR;
		counterL=counterR=0;
		for(i=p;i<=r;i++)
			if(L[counterL]<=R[counterR])
				arr[i]=L[counterL++];
			else
				arr[i]=R[counterR++];
	}
	
	public static void Merge_Sort(int[]arr,int p,int r)
	{
		if(p<r)
		{	
			int q=(p+r)/2;
			Merge_Sort(arr,p,q);
			Merge_Sort(arr,q+1,r);
			Merge(arr,p,q,r);
		}
	}
}